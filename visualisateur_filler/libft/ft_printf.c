/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:08:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 19:02:26 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "libft.h"
#include <unistd.h>

static void	find_arg_len(va_list ap, t_printf *argument_specs)
{
	va_list copy;

	va_copy(copy, ap);
	if (ft_strchr("ouxXdiOUDbp", argument_specs->type))
		argument_specs->arg_len = get_number_len(copy, argument_specs);
	else if (ft_strchr("cCsS", argument_specs->type))
		argument_specs->arg_len = get_char_len(copy, argument_specs);
}

static void	parsing_handler(const char *format, va_list ap, t_str *argument_str)
{
	t_printf	argument_specs;

	while (format && *format)
	{
		argument_specs = initialize_elem();
		format = store_string(format, argument_str);
		format = parse(format, &argument_specs, ap);
		if (!argument_specs.type && format && *format)
		{
			update_str(argument_str, (void*)format, 1);
			format++;
		}
		if (argument_specs.type)
			find_arg_len(ap, &argument_specs);
		if (argument_specs.width
			|| argument_specs.activate_precision || argument_specs.sharp ||
			argument_specs.show_sign)
			apply_precision_width(&argument_specs, argument_str);
		if (argument_specs.type && (argument_specs.arg_len
				|| ft_strchr("sScC", argument_specs.type)))
			treat_and_store_argument(ap, &argument_specs, argument_str);
		if (argument_specs.width && argument_specs.left_align_output)
			apply_width(&argument_specs, argument_str);
	}
}

int			launch_string_print(const char *format, va_list ap,
		t_str *argument_str, int flush)
{
	static int	return_val = 0;

	if (flush)
	{
		return_val += write(1, argument_str->str, argument_str->position);
		argument_str->position = 0;
	}
	argument_str->position = 0;
	if (!flush)
		parsing_handler(format, ap, argument_str);
	return (write(set_get_fd(0), argument_str->str,
				argument_str->position) + return_val);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			return_val;
	t_str		argument_str;

	return_val = -1;
	if (!(format))
	{
		ft_putstr_fd("Please stop fooling around with my ft_printf.", 2);
		return (-1);
	}
	va_start(ap, format);
	return_val = launch_string_print(format, ap, &argument_str, 0);
	va_end(ap);
	if (set_get_fd(0) != 1)
		close(set_get_fd(0));
	return (return_val);
}
