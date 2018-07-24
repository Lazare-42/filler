/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:13:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:56:29 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	apply_flag_padding(t_printf *argument_specs, t_str *argument_str)
{
	char	fill;

	fill = (argument_specs->precision < argument_specs->width &&
			argument_specs->precision != -1) ? ' ' : '0';
	if (argument_specs->arg_len >= argument_specs->width)
		return ;
	if (!((*argument_specs).left_align_output))
	{
		if (ft_strchr("dDioOuUxX", argument_specs->type) &&
				argument_specs->sign[0] && fill == '0')
		{
			update_str(argument_str, (void*)&argument_specs->sign[0], 1);
			update_str(argument_str, (void*)&fill, 1);
			return ;
		}
		update_str(argument_str, (void*)&fill, 1);
		update_str(argument_str, (void*)&argument_specs->sign[0], 1);
	}
}

void	apply_plus_minus_flags(t_printf *argument_specs, t_str *argument_str)
{
	if (!(argument_specs->type))
		return ;
	if (ft_strchr("cCsOouS", argument_specs->type))
		return ;
	update_str(argument_str, (void*)&argument_specs->show_sign, 1);
}

void	apply_precision(t_printf *argument_specs, t_str *argument_str)
{
	char		fill;
	int			i;

	fill = '0';
	i = 0;
	if (!(argument_specs->type))
		return ;
	if (argument_specs->precision && argument_specs->type == 'o'
			&& argument_specs->sharp && argument_specs->arg_len)
		argument_specs->precision--;
	if (argument_specs->precision <= argument_specs->arg_len)
		return ;
	while (i++ < argument_specs->precision - argument_specs->arg_len)
		update_str(argument_str, (void*)&fill, 1);
}

void	apply_sharp(t_printf *argument_specs, t_str *argument_str)
{
	char fill;

	fill = '0';
	if (ft_strchr("cCsC", argument_specs->type))
		return ;
	if (!argument_specs->type)
		return ;
	update_str(argument_str, (void*)&fill, 1);
	if (ft_strchr("xXp", argument_specs->type))
	{
		fill = (argument_specs->type == 'X') ? 'X' : 'x';
		update_str(argument_str, (void*)&fill, 1);
	}
}
