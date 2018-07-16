/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 19:37:02 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

static char		*store_string(char *format, t_printf *argument)
{
	while (format && *format && *format != '%')
	{
		if (*format == '[' && *(1 + format) && *(1 + format) == '[')
			format = terminal_formatting(format, argument);
		if (format && *format && *format != '%')
		{
			argument->to_store = (void*)format;
			store_print_handler(argument, 1, 0, 1);
			format++;
		}
	}
	if (format && *format == '%')
	{
		argument->percentage_presence = 1;
		format++;
	}
	return (format);
}

static char		*type_0_modifications(char *format, t_printf *argument)
{
	if (argument->percentage_presence && *format != '%')
	{
		argument->to_store = (void*)format;
		store_print_handler(argument, 3, 1, 1);
		format++;
	}
	else if (*format == '%')
	{
		argument->to_store = (void*)format;
		store_print_handler(argument, 3, 1, 1);
		format++;
	}
	return (format);
}

int		get_type(t_printf *argument, char *format)
{
	char *tmp;

	tmp = format;
	if (*format == 'i')
		argument->type = 'd';
	else
		argument->type = *format;
	if (*format == 'p')
		argument->sharp = 1;
	if (argument->show_sign && ft_strchr("xXpc", *format))
	{
		argument->show_sign = 0;
	}
	else if (ft_strchr("xX", argument->type) && argument->sharp
			&& argument->width > 1)
		argument->width--;
	format++;
	return (format - tmp);
}

char			*parse(char *format, t_printf *argument, va_list ap)
{
	int tmp;

	tmp = 1;
	format = store_string(format, argument);
	while (format && *format && tmp)
	{
		tmp = 0;
		if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAnb", *format))
			format  += get_type(argument, format);
		else if (ft_strchr("-0+ #", *format)
				&& (tmp = get_flags(argument, format)))
			format += tmp;
		else if((ft_isdigit(*format) || *format == '*')
				&& !argument->precision
				&& (tmp = get_width(ap, argument, format)))
			format += tmp;
		else if (*format == '.' && (tmp = get_precision(ap, argument, format)))
			format += tmp;
		else if (format && ft_strchr("hhljz", *format))
			if ((tmp = get_modifier(argument, format)))
				format  += tmp;
	}
	if (!argument->type && format && *format)
		format = type_0_modifications(format, argument);
	return (format);
}
