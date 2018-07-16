/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:08:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 19:34:30 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../includes/libft.h"

/*
 ** the fonction parse stores the string argument
 ** in a string in a structure of a linked list.
 ** If it meets an argument it
 ** sends the structure and the va_list element
 ** to the function treat_and_store elements which stores all required elements
 ** (width, precision, argument itself) in the structure and eventually sends
 ** the structure and its element to the precision and width handler,
 ** apply_precision_width
 ** If any error is encoutered set_get_return is set to -1. Else the function
 ** ft_printf returns from the write function in print_list()
 */

static void		apply_precision_width(t_printf *argument)
{
	if (argument->sharp && ft_strchr("xoXp", argument->type)
			&& !argument->left_align_output)
		apply_sharp(argument);
	if (argument->show_sign && argument->left_align_output > -1)
		apply_plus_minus_flags(argument);
	if (argument->precision != -1 && argument->left_align_output == 1
			&& argument->type)
		apply_precision(argument);
	if (argument->width)
		apply_width(argument);
	if (argument->sharp && ft_strchr("xoXpO", argument->type)
			&& argument->left_align_output)
		apply_sharp(argument);
	if (argument->left_align_output == 1)
		apply_flag_padding(argument);
	if (argument->show_sign && argument->left_align_output == -1)
		apply_plus_minus_flags(argument);
	if (argument->precision > 0 && argument->left_align_output <= 0
			&& argument->type)
		apply_precision(argument);
}

static void		treat_and_store_argument(va_list ap, t_printf *argument)
{
	if (ft_strchr("ouxXdiOUDb", argument->type))
		store_number_data(ap, argument);
	else
		store_char_data(ap, argument);
	if (argument->sharp && argument->type)
	{
		if (argument->width >= argument->precision && argument->type != 'o')
			argument->width--;
		if (!ft_strchr("xX", argument->type))
			(argument->width >= argument->precision) ? argument->width-- : 0;
		if (argument->type == 'o' && argument->sharp
				&& argument->precision > argument->arg_len)
			argument->precision--;
	}
}

static t_printf	initialize_elem(void)
{
	t_printf argument;

	argument.type = 0;
	ft_memset(argument.modifier, 0, 3);
	ft_memset(argument.sign, 0, 3);
	argument.before_len = 0;
	argument.before_arg_len = 0;
	argument.arg_len = 0;
	argument.width = 0;
	argument.sharp = 0;
	argument.precision = 0;
	argument.show_sign = 0;
	argument.percentage_presence = 0;
	argument.left_align_output = -1;
	return (argument);
}

static void		parsing_handler(char *format, va_list ap)
{
	t_printf	argument;

	argument = initialize_elem();
	format = parse(format, &argument, ap);
	if (argument.type)
		treat_and_store_argument(ap, &argument);
	if (argument.width ||
			argument.precision > -1 || argument.sharp)
		apply_precision_width(&argument);
	store_print_handler(&argument, 4, 0, 0);
	if (format && *format)
		parsing_handler(format, ap);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;

	if (!(format))
	{
		ft_putstr_fd("Please stop fooling around with my ft_printf.", 2);
		return (-1);
	}
	va_start(ap, format);
	parsing_handler((char*)format, ap);
	va_end(ap);
	store_print_handler(NULL, 0, 0, 0);
	return (set_get_return(0));
}
