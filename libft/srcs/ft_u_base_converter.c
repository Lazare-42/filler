/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:04:29 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <inttypes.h>

/*
** u in ft_u_base_converter stands for unsigned base converter
** take_out_bits' utility is to take out bits if a signed value has been passed
** to the function ; and this value type is smaller than a uintmax_t ; the
** largest possible type in C
*/

unsigned long long	take_out_bits(uintmax_t to_change, int sizeof_var)
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

char				*ft_u_base_converter(int base_size, uintmax_t number,
		int sizeof_var)
{
	static char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		*result;

	result = NULL;
	number = take_out_bits(number, sizeof_var);
	if (base_size > 36)
	{
		return (ft_put_error_return_null("maximum base is 36",
					"ft_u_base_converter"));
	}
	if (!(result))
	{
		if (!(result = ft_strnew(1)))
			return (ft_put_error_return_null("malloc error",
						"ft_u_base_converter"));
	}
	(number == 0) ? result[0] = '0' : 0;
	while (number)
	{
		if (!(result = ft_strjoinfree_char_str((base_output[number % base_size])
						, &result)))
			break ;
		number /= base_size;
	}
	return (result);
}
