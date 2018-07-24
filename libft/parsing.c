/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:55:09 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*store_string(const char *format, t_str *argument_str)
{
	while (format && *format && *format != '%')
	{
		if (*format == '[' && *(1 + format) && *(1 + format) == '[')
			format = terminal_formatting(format, argument_str);
		if (format && *format && *format != '%')
		{
			update_str(argument_str, (void*)format, 1);
			format++;
		}
	}
	if (format && *format == '%')
		format++;
	return (format);
}

void		get_type(t_printf *argument, const char *format)
{
	if (*format == 'i')
		argument->type = 'd';
	else
		argument->type = *format;
	if (*format == 'p')
	{
		argument->sharp = 1;
		if (argument->width)
			argument->width--;
		if (argument->width)
			argument->width--;
	}
	if (argument->type == 'c')
		argument->activate_precision = 0;
	if (argument->show_sign && ft_strchr("xXpc", *format))
		argument->show_sign = 0;
	if (argument->activate_precision && argument->zeros_width
			&& !ft_strchr("sScC", argument->type))
		argument->zeros_width = 0;
}

const char	*parse(const char *format, t_printf *argument, va_list ap)
{
	int tmp;

	tmp = 1;
	while (format && *format && tmp)
	{
		tmp = 0;
		if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAnb", *format))
		{
			get_type(argument, format);
			format++;
		}
		else if (ft_strchr("-0+ #", *format)
				&& (tmp = get_flags(argument, format)))
			format += tmp;
		else if ((ft_isdigit(*format) || *format == '*')
				&& argument->precision == 1
				&& (tmp = get_width(ap, argument, format)))
			format += tmp;
		else if (*format == '.' && (tmp = get_precision(ap, argument, format)))
			format += tmp;
		else if (format && ft_strchr("hhljz", *format))
			if ((tmp = get_modifier(argument, format)))
				format += tmp;
	}
	return (format);
}
