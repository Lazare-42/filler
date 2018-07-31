/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:59:38 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>
#include <stdio.h>

int							u_base_converter_len(int base_size,
		uintmax_t number, int sizeof_var, t_printf *argument)
{
	int			i;

	i = 0;
	number = take_out_bits(number, sizeof_var);
	(number == 0) ? i++ : 0;
	if (number == 0 && ft_strchr("oO", argument->type) && argument->precision)
		argument->sharp = 0;
	if (number == 0 && ft_strchr("xX", argument->type))
		argument->sharp = 0;
	if (number == 0 && ft_strchr("xXoO", argument->type)
			&& !argument->precision && argument->width > 0)
		argument->width++;
	if (number != 0 && ft_strchr("xXoO", argument->type)
			&& argument->width >= 1 && argument->sharp)
		argument->width--;
	if (ft_strchr("xX", argument->type)
			&& argument->width >= 1 && argument->sharp)
		argument->width--;
	while (number)
	{
		number /= base_size;
		i++;
	}
	return (i);
}

int							s_base_converter_len(int base_size,
		intmax_t number, int sizeof_var, t_printf *argument)
{
	int				i;

	i = 0;
	if (number == 0 && argument->precision == 0)
		return (0);
	number = convert_overflow(sizeof_var, number);
	if (number < 0)
	{
		argument->show_sign = '-';
		number *= -1;
	}
	(number == 0) ? i++ : 0;
	while (number != 0)
	{
		number /= base_size;
		i++;
	}
	return (i);
}
