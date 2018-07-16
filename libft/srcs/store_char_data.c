/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_store_argument.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:30:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:01:50 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
#include <stdarg.h>

void		store_str_data(va_list ap, t_printf *argument)
{
	char	*va_arg_str;

	va_arg_str = NULL;
	if (argument->precision < 0)
		return ;
	va_arg_str = va_arg(ap, char *);
	if (!va_arg_str)
	{
		argument->to_store = (void*)"(null)";
		if (argument->precision && argument->precision < 6)
			store_print_handler(argument, 3, 1, argument->precision);
		else
			store_print_handler(argument, 3, 1, 6);
		return ;
	}
	argument->to_store = (void*)va_arg_str;
	if (argument->precision > 0
			&& argument->precision < (int)ft_strlen(va_arg_str))
		store_print_handler(argument, 3, 1, argument->precision);
	else
		store_print_handler(argument, 3, 1, ft_strlen(va_arg_str));
}

void		store_char_data(va_list ap, t_printf *argument)
{
	char c;

	if (argument->type == 's' && !*argument->modifier)
		store_str_data(ap, argument);
	else if ((*argument).type == 'c' && !*argument->modifier)
	{
		c = va_arg(ap, int);
		argument->to_store = (void*)&c;
		store_print_handler(argument, 3, sizeof(char), 1);
	}
	else if (argument->type == 'C'
			|| (argument->type == 'c' && *argument->modifier == 'l'))
		store_unicode(va_arg(ap, wint_t), argument, 4);
	else if (argument->type == 'S'
			|| (argument->type == 's' && *argument->modifier == 'l'))
		store_unicode_str(va_arg(ap, wchar_t*), argument);
	if ((*argument).type == 'p')
		get_hex_ptr_adr(ap, argument);
}
