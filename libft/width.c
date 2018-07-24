/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:08:12 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:50:47 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		apply_width_to_string(t_printf *argument_specs, t_str *argument_str,
		char fill_val)
{
	char	tmp;

	tmp = argument_str->str[argument_str->position - 1];
	if (!(argument_specs->left_align_output))
		argument_str->position--;
	while (argument_specs->width-- > 1)
		update_str(argument_str, (void*)&fill_val, 1);
	if (!(argument_specs->left_align_output))
		update_str(argument_str, (void*)&tmp, 1);
}

void		apply_width(t_printf *argument_specs, t_str *argument_str)
{
	char	fill_val;
	int		i;

	if (argument_specs->arg_len >= argument_specs->width)
		return ;
	fill_val = ' ';
	if (argument_specs->zeros_width && !argument_specs->left_align_output
			&& (!argument_specs->activate_precision
				|| argument_specs->type == 's' || !argument_specs->type))
		fill_val = '0';
	i = 0;
	if (argument_specs->type)
	{
		if (argument_specs->precision > 1
				&& argument_specs->precision > argument_specs->arg_len
				&& !ft_strchr("SsCc", argument_specs->type))
		{
			while (i++ < argument_specs->width - argument_specs->precision)
				update_str(argument_str, (void*)&fill_val, 1);
		}
			else while (i++ < argument_specs->width - argument_specs->arg_len)
				update_str(argument_str, (void*)&fill_val, 1);
	}
	else
		apply_width_to_string(argument_specs, argument_str, fill_val);
}
