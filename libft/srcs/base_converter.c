/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:33:42 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
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

void						get_hex_ptr_adr(va_list ap, t_printf *argument)
{
	void	*test_data;

	test_data = NULL;
	test_data = va_arg(ap, void*);
	if (test_data == 0 && argument->precision >= 0)
	{
		argument->to_store = (void*)"0";
		store_print_handler(argument, 3, 0, 1);
	}
	else
		printf_u_base_converter(16, (uintptr_t)test_data,
				sizeof(uintptr_t), argument);
}

static intmax_t				convert_overflow(int sizeof_var, intmax_t number)
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

static unsigned long long	take_out_bits(uintmax_t to_change, int sizeof_var)
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

void						printf_u_base_converter(int base_size,
		uintmax_t number, int sizeof_var, t_printf *argument)
{
	static char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		result[65];
	int			i;

	i = 0;
	number = take_out_bits(number, sizeof_var);
	(number == 0) ? result[64] = '0' : 0;
	if ((!argument->precision && argument->type == 'o')
			|| ft_strchr("xX", argument->type))
		(number == 0 && argument->sharp && !ft_strchr("pOo", argument->type)) ?
			argument->sharp = 0 : 0;
	(number == 0) ? i++ : 0;
	if (number == 0 && ((argument->sharp && argument->type == 'o')
				|| argument->precision == -1))
		return ;
	while (number)
	{
		result[64 - i] = base_output[number % base_size];
		number /= base_size;
		i++;
	}
	if (argument->type == 'X')
		ft_str_mins_to_caps(&result[65] - i);
	argument->to_store = &result[65 - i];
	store_print_handler(argument, 3, sizeof(char), i);
}

void						printf_s_base_converter(int base_size,
		intmax_t number, int sizeof_var, t_printf *argument)
{
	static	char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char			result[65];
	int				i;

	i = 0;
	if (number == 0 && argument->precision == -1)
		return ;
	number = convert_overflow(sizeof_var, number);
	if (number < 0)
		argument->show_sign = '-';
	if (number < 0)
		number *= -1;
	(number == 0) ? result[64] = '0' : 0;
	(number == 0) ? i++ : 0;
	while (number != 0)
	{
		result[64 - i] = base_output[(number % base_size < 0) ?
			-(number % base_size) : number % base_size];
		number /= base_size;
		i++;
	}
	argument->to_store = &result[65 - i];
	store_print_handler(argument, 3, sizeof(char), i);
}
