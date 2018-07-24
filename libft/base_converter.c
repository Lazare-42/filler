/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:55:26 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>
#include <stdio.h>

/*
** u in ft_u_base_converter stands for unsigned base converter
** take_out_bits' utility is to take out bits if a signed value has been passed
** to the function ; and this value type is smaller than a uintmax_t ; the
** largest possible type in C
**
** The get_hex_ptr_adr function produces the string for the %p type
** FYI uintptr_t is the only type guaranteed to hold a pointer value
** argument_precision is only present because printf("%p, (void*)0)
** procuces 0x0 whereas printf("%.p, (void*)0) produces 0x
*/

intmax_t				convert_overflow(int sizeof_var, intmax_t number)
{
	if ((int)sizeof(number) > sizeof_var)
	{
		if (sizeof_var == sizeof(char))
			number = (char)number;
		if (sizeof_var == sizeof(short))
			number = (short)number;
		if (sizeof_var == sizeof(int))
			number = (int)number;
		if (sizeof_var == sizeof(long))
			number = (long)number;
		if (sizeof_var == sizeof(long long))
			number = (long long)number;
		if (sizeof_var > (int)sizeof(long long))
			number = (intmax_t)number;
	}
	return (number);
}

unsigned long long		take_out_bits(uintmax_t to_change, int sizeof_var)
{
	static unsigned long long	all_bits_long_long = ~0;
	static unsigned long		all_bits_long = ~0;
	static unsigned int			all_bits_int = ~0;
	static unsigned short		all_bits_short = ~0;
	static unsigned char		all_bits_char = ~0;

	if (sizeof(unsigned long long) == sizeof_var)
		to_change &= all_bits_long_long;
	else if (sizeof(unsigned long) == sizeof_var)
		to_change &= all_bits_long;
	else if (sizeof(unsigned int) == sizeof_var)
		to_change &= all_bits_int;
	else if (sizeof(unsigned short) == sizeof_var)
		to_change &= all_bits_short;
	else if (sizeof(unsigned char) == sizeof_var)
		to_change &= all_bits_char;
	return (to_change);
}

void					printf_u_base_converter(int base_size,
		uintmax_t number, int sizeof_var, t_printf *argument)
{
	static char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		result[65];
	int			i;

	i = 0;
	number = take_out_bits(number, sizeof_var);
	if ((number == 0 && argument->precision == 0) ||
			(number == 0 && argument->sharp && argument->type != 'p'))
		return ;
	(number == 0) ? result[64] = '0' : 0;
	(number == 0) ? i++ : 0;
	while (number)
	{
		result[64 - i] = base_output[number % base_size];
		number /= base_size;
		i++;
	}
	if (argument->type == 'X')
		ft_str_mins_to_caps(&result[65] - i);
	update_str(argument->argument_str, (void*)&result[65 - i], i);
}

void					printf_s_base_converter(int base_size,
		intmax_t number, int sizeof_var, t_printf *argument)
{
	static	char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char			result[65];
	int				i;

	i = 0;
	if (number == 0 && argument->precision == 0)
		return ;
	number = convert_overflow(sizeof_var, number);
	if (number < 0)
		number *= -1;
	(number == 0) ? i++ : 0;
	(number == 0) ? result[64] = '0' : 0;
	while (number)
	{
		result[64 - i] = base_output[(number % base_size < 0) ?
			-(number % base_size) : number % base_size];
		number /= base_size;
		i++;
	}
	if (argument->type == 'X')
		ft_str_mins_to_caps(&result[65] - i);
	update_str(argument->argument_str, (void*)&result[65 - i], i);
}
