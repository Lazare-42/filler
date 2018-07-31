/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_continued.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:35:52 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:59:14 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		treat_and_store_argument(va_list ap, t_printf *argument_specs,
		t_str *argument_str)
{
	argument_specs->argument_str = argument_str;
	if (ft_strchr("opuxXdiOUDb", argument_specs->type))
		store_number_data(ap, argument_specs);
	else
		store_char_data(ap, argument_specs, argument_str);
}

void		adjust_width_precision_for_sign(t_printf *argument_specs)
{
	if (argument_specs->arg_len >= argument_specs->width
		&& argument_specs->arg_len >= argument_specs->precision)
		return ;
	else if (argument_specs->width > argument_specs->precision)
		argument_specs->width--;
}

void		apply_precision_width(t_printf *argument_specs, t_str *argument_str)
{
	if (ft_strchr("sS", argument_specs->type) && argument_specs->precision
			< argument_specs->arg_len && argument_specs->activate_precision)
		argument_specs->arg_len = argument_specs->precision;
	if (argument_specs->show_sign)
		adjust_width_precision_for_sign(argument_specs);
	if (argument_specs->show_sign && argument_specs->zeros_width)
		apply_plus_minus_flags(argument_specs, argument_str);
	if (argument_specs->sharp && argument_specs->zeros_width)
		apply_sharp(argument_specs, argument_str);
	if (argument_specs->width && !(argument_specs->left_align_output))
		apply_width(argument_specs, argument_str);
	if (argument_specs->sharp && !argument_specs->zeros_width)
		apply_sharp(argument_specs, argument_str);
	if (argument_specs->show_sign && !argument_specs->zeros_width)
		apply_plus_minus_flags(argument_specs, argument_str);
	if (argument_specs->activate_precision
			&& !ft_strchr("sSCc", argument_specs->type))
		apply_precision(argument_specs, argument_str);
}

t_printf	initialize_elem(void)
{
	t_printf argument;

	argument.type = 0;
	ft_memset(argument.modifier, 0, 3);
	ft_memset(argument.sign, 0, 3);
	argument.arg_len = 0;
	argument.width = 0;
	argument.sharp = 0;
	argument.zeros_width = 0;
	argument.precision = 1;
	argument.activate_precision = 0;
	argument.show_sign = 0;
	argument.percentage_presence = 0;
	argument.left_align_output = 0;
	return (argument);
}
