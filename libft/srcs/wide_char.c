/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:52:50 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 13:51:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

void		send_unicode(void *c, t_printf *argument, int byte_size)
{
	argument->to_store = c;
	store_print_handler(argument, 3, byte_size, byte_size);
}

void		store_unicode(wint_t data, t_printf *argument, int precision)
{
	unsigned char	c[3];

	c[0] = data;
	if (data < 128 && precision)
		send_unicode(c, argument, 1);
	else if (data < 2048 && precision > 1)
	{
		c[0] = (0b00011111 & (data >> 6)) | 0b11000000;
		c[1] = (0b00111111 & data) | 0b10000000;
		send_unicode(c, argument, 2);
	}
	else if ((data < 131071 || data < 41943004) && precision > 2)
	{
		if (data > 131071)
		{
			if (precision == 3)
				return ;
			c[0] = (0b00001111 & (data >> 18)) | 0b11100000;
			send_unicode((void*)&c, argument, 1);
		}
		c[0] = (0b00001111 & (data >> 12)) | 0b11100000;
		c[1] = (0b00111111 & (data >> 6)) | 0b10000000;
		c[2] = (0b00111111 & data) | 0b10000000;
		send_unicode((void*)&c, argument, 3);
	}
}

void		store_unicode_str(wchar_t *data, t_printf *argument)
{
	int precision_absence;

	precision_absence = 1;
	if (argument->precision)
		precision_absence = 0;
	if (argument->precision < 0)
		argument->precision = 0;
	if (!data)
	{
		argument->to_store = (void*)"(null)";
		store_print_handler(argument, 3, 6, 6);
	}
	else
		while (*data && (precision_absence || argument->precision > 0))
		{
			if (precision_absence)
				store_unicode(*data, argument, 4);
			else if (argument->precision)
				store_unicode(*data, argument, argument->precision
						- argument->arg_len);
			data++;
		}
}
