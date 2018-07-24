/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_store_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:58:39 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:58:04 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	type_to_int_base(char type)
{
	if (ft_strchr("oO", type))
		return (8);
	else if (ft_strchr("uUdiD", type))
		return (10);
	else
		return (16);
}

static int	store_data_len(va_list ap, t_printf *argument)
{
	if (!(ft_strcmp("hh", argument->modifier)))
		return (u_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, unsigned int), sizeof(unsigned char), argument));
	else if (*argument->modifier == 'h')
		return (u_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, unsigned int), sizeof(unsigned short), argument));
	else if (*argument->modifier == 'l')
	{
		return (u_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, unsigned long), sizeof(unsigned long), argument));
	}
	else if (!(ft_strcmp("ll", argument->modifier)))
	{
		return (u_base_converter_len(type_to_int_base(argument->type),
		va_arg(ap, unsigned long long), sizeof(unsigned long long), argument));
	}
	else if (*argument->modifier == 'j')
		return (u_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, uintmax_t), sizeof(uintmax_t), argument));
	else if (*argument->modifier == 'z')
	{
		return (u_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, size_t), sizeof(size_t), argument));
	}
	return (0);
}

static int	store_data_len_modifier(va_list ap, t_printf *argument)
{
	if (!(ft_strcmp("hh", argument->modifier)))
		return (s_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, int), sizeof(signed char), argument));
	else if (*argument->modifier == 'h')
		return (s_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, int), sizeof(short), argument));
	else if (!(ft_strcmp("ll", argument->modifier)))
		return (s_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, long long), sizeof(long long), argument));
	else if (*argument->modifier == 'l')
		return (s_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, long), sizeof(long), argument));
	else if (*argument->modifier == 'j')
		return (s_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, intmax_t), sizeof(intmax_t), argument));
	else if (*argument->modifier == 'z')
	{
		return (s_base_converter_len(type_to_int_base(argument->type),
				va_arg(ap, size_t), sizeof(size_t), argument));
	}
	return (0);
}

int			get_number_len_continued(va_list ap, t_printf *argument)
{
	if (argument->type == 'p')
	{
		return (u_base_converter_len(16,
				va_arg(ap, size_t), sizeof(size_t), argument));
	}
	return (0);
}

int			get_number_len(va_list ap, t_printf *argument)
{
	if (argument->type == 'd')
		if (!((*argument->modifier)))
			return (s_base_converter_len(type_to_int_base((*argument).type),
						va_arg(ap, int), sizeof(int), argument));
		else
			return (store_data_len_modifier(ap, argument));
	else if ((ft_strchr("ouxX", (*argument).type)) && ((*argument->modifier)))
		return (store_data_len(ap, argument));
	else if (ft_strchr("ouxX", (*argument).type))
		return (u_base_converter_len(type_to_int_base((*argument).type),
				va_arg(ap, int), sizeof(int), argument));
	else if (ft_strchr("OU", (*argument).type))
		return (u_base_converter_len(type_to_int_base((*argument).type),
				va_arg(ap, long int), sizeof(long int), argument));
	else if (argument->type == 'D')
		return (s_base_converter_len(type_to_int_base((*argument).type),
				va_arg(ap, long int), sizeof(long int), argument));
	else if (argument->type == 'b')
	{
		return (s_base_converter_len(va_arg(ap, int),
				va_arg(ap, intmax_t), sizeof(intmax_t), argument));
	}
	return (get_number_len_continued(ap, argument));
}
