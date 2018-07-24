/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:07 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:54:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** flag - which left aligns output and flag 0 which prepends 0 in front
** both use same element of the structure left_align_output as they cannot
** coexist. Default left_align_output is -1
*/

int		get_precision(va_list ap, t_printf *argument, const char *format)
{
	const char	*tmp;

	tmp = format;
	format++;
	argument->activate_precision = 1;
	if (*format == '*' && format++)
	{
		argument->precision = va_arg(ap, int);
		if (argument->precision < 0)
		{
			argument->activate_precision = 0;
			argument->left_align_output = 0;
		}
	}
	else if (*format && *format != '*' && (!(ft_isdigit(*format))
				|| *format == '0'))
		argument->precision = 0;
	else if (*format && ft_isdigit(*format))
		argument->precision = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format - tmp);
}

int		get_width(va_list ap, t_printf *argument, const char *format)
{
	const char	*tmp;

	tmp = format;
	if (format && ft_isdigit(*format))
	{
		argument->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else if (format && *format == '*' && format++)
		argument->width = va_arg(ap, int);
	if (argument->width < 0)
	{
		argument->width *= -1;
		argument->left_align_output = 1;
	}
	return (format - tmp);
}

int		get_flags(t_printf *argument, const char *format)
{
	const char	*tmp;

	tmp = format;
	while (format && (*format == '-' || *format == '0' || *format == '+'
				|| *format == ' ' || *format == '#'))
	{
		if (*format == '-')
			argument->left_align_output = 1;
		if (*format == '0')
			argument->zeros_width = 1;
		if (*format == ' ' && (*argument).show_sign != '+'
				&& !argument->sharp)
			argument->show_sign = ' ';
		if (*format == '+' && !argument->sharp)
			argument->show_sign = '+';
		if (*format == '#')
		{
			argument->sharp = 1;
			argument->show_sign = 0;
		}
		format++;
	}
	return (format - tmp);
}

int		get_modifier(t_printf *argument, const char *format)
{
	const char	*tmp;

	tmp = format;
	(*argument).modifier[0] = *format++;
	if (!(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", *format)))
		(*argument).modifier[1] = *format++;
	return (format - tmp);
}
