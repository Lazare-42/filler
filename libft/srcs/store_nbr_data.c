/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_store_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:58:39 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 16:18:17 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

static int	type_to_int_base(char type)
{
	if (ft_strchr("oO", type))
		return (8);
	else if (ft_strchr("uUdiD", type))
		return (10);
	else
		return (16);
}

static void	treat_store_modifier_u_data(va_list ap, t_printf *argument)
{
	if (!(ft_strcmp("hh", argument->modifier)))
		printf_u_base_converter(type_to_int_base(argument->type),
				va_arg(ap, unsigned int), sizeof(unsigned char), argument);
	else if (*argument->modifier == 'h')
		printf_u_base_converter(type_to_int_base(argument->type),
				va_arg(ap, unsigned int), sizeof(unsigned short), argument);
	else if (*argument->modifier == 'l')
	{
		printf_u_base_converter(type_to_int_base(argument->type),
				va_arg(ap, unsigned long), sizeof(unsigned long), argument);
	}
	else if (!(ft_strcmp("ll", argument->modifier)))
	{
		printf_u_base_converter(type_to_int_base(argument->type),
				va_arg(ap, unsigned long long), sizeof(unsigned long long),
				argument);
	}
	else if (*argument->modifier == 'j')
		printf_u_base_converter(type_to_int_base(argument->type),
				va_arg(ap, uintmax_t), sizeof(uintmax_t), argument);
	else if (*argument->modifier == 'z')
		printf_u_base_converter(type_to_int_base(argument->type),
				va_arg(ap, size_t), sizeof(size_t), argument);
}

static void	treat_store_modifier_s_data(va_list ap, t_printf *argument)
{
	if (!(ft_strcmp("hh", argument->modifier)))
		printf_s_base_converter(type_to_int_base(argument->type),
				va_arg(ap, int), sizeof(signed char), argument);
	else if (*argument->modifier == 'h')
		printf_s_base_converter(type_to_int_base(argument->type),
				va_arg(ap, int), sizeof(short), argument);
	else if (!(ft_strcmp("ll", argument->modifier)))
		printf_s_base_converter(type_to_int_base(argument->type),
				va_arg(ap, long long), sizeof(long long),
				argument);
	else if (*argument->modifier == 'l')
		printf_s_base_converter(type_to_int_base(argument->type),
				va_arg(ap, long), sizeof(long), argument);
	else if (*argument->modifier == 'j')
		printf_s_base_converter(type_to_int_base(argument->type),
				va_arg(ap, intmax_t), sizeof(intmax_t), argument);
	else if (*argument->modifier == 'z')
		printf_s_base_converter(type_to_int_base(argument->type),
				va_arg(ap, size_t), sizeof(size_t), argument);
}

void		store_number_data(va_list ap, t_printf *argument)
{
	if (argument->type == 'd')
	{
		if (!((*argument->modifier)))
			printf_s_base_converter(type_to_int_base((*argument).type),
					va_arg(ap, int), sizeof(int), argument);
		else
			treat_store_modifier_s_data(ap, argument);
	}
	else if ((ft_strchr("ouxX", (*argument).type)) && ((*argument->modifier)))
		treat_store_modifier_u_data(ap, argument);
	else if (ft_strchr("ouxX", (*argument).type))
		printf_u_base_converter(type_to_int_base((*argument).type),
				va_arg(ap, int), sizeof(int), argument);
	else if (ft_strchr("OU", (*argument).type))
		printf_u_base_converter(type_to_int_base((*argument).type),
				va_arg(ap, long int), sizeof(long int), argument);
	else if (argument->type == 'D')
		printf_s_base_converter(type_to_int_base((*argument).type),
				va_arg(ap, long int), sizeof(long int), argument);
	else if (argument->type == 'b')
		printf_s_base_converter(va_arg(ap, int),
				va_arg(ap, intmax_t), sizeof(intmax_t), argument);
}
