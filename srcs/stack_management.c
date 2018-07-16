/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_store_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:44:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:35:48 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "../includes/libft.h"
#include <pthread.h>

static unsigned char	g_str[BUFF_SIZE];
static int			 	g_bytes_in_final_str = 0;
static unsigned char	g_final_str[BUFF_SIZE * 3];
static int				g_return_val = 0;
static void				print(t_printf *arg, int location);

int						set_get_return(int action)
{
	int			final_ret;

	if (action < 0)
		g_return_val = action;
	if (g_return_val < 0)
		return (g_return_val);
	else if (action > 0)
		g_return_val += action;
	if (!action)
	{
		final_ret = g_return_val;
		g_return_val = 0;
		return (final_ret);
	}
	return (g_return_val);
}

void					store_values(t_printf *arg, int buff_location,
		int src_len, int sizeof_memop)
{
	unsigned char	*src_byte;
	unsigned char	*dst_byte;
	int				*dst_location;
	int				i;

	i = 0;
	dst_byte = g_str + buff_location;
	src_byte = arg->to_store;
	if (arg->location == 1)
		dst_location = &(arg->before_len);
	else if (arg->location == 2)
		dst_location = &(arg->before_arg_len);
	else
		dst_location = &(arg->arg_len);
	while (sizeof_memop--)
	{
		if (*dst_location == BUFF_SIZE / 3)
			print(arg, -arg->location);
		dst_byte[*dst_location] = src_byte[i];
		(*dst_location)++;
		if (src_len)
			i++;
	}
}

void				manage_buf(void *str, int write_size)
{
	unsigned char	*final_str;

	final_str = str;
	if (g_bytes_in_final_str + write_size > BUFF_SIZE * 3)
	{
		set_get_return(write(1, &g_final_str, g_bytes_in_final_str)
				+ set_get_return(0));
		g_bytes_in_final_str = 0;
	}
	ft_memcpy(g_final_str + g_bytes_in_final_str, final_str, write_size);
	g_bytes_in_final_str = write_size + g_bytes_in_final_str;
}


static void				print(t_printf *arg, int location)
{
	int				write_size;
	char			final_str[BUFF_SIZE];

	write_size = 0;
	ft_memcpy(final_str, g_str, arg->before_len);
	write_size += arg->before_len;
	arg->before_len = 0;
	if (location == -2 || location == -3 || location == 4)
	{
		ft_memcpy(final_str + write_size, g_str
				+ BUFF_SIZE / 3, arg->before_arg_len);
		write_size += arg->before_arg_len;
		arg->before_arg_len = 0;
	}
	if (location == -3 || location == 4)
	{
		ft_memcpy(final_str + write_size, g_str + 2
				* (BUFF_SIZE / 3), arg->arg_len);
		write_size += arg->arg_len;
		arg->arg_len = 0;
	}
	if (write_size)
		manage_buf((void*)final_str, write_size);
}

void					store_print_handler(t_printf *arg,
		int location, int src_len, int sizeof_memop)
{
	pthread_mutex_t mutex;

	if (pthread_mutex_trylock(&mutex))
		set_get_return(-1);
	if (location > 0)
		arg->location = location;
	if (location == 1)
		store_values(arg, 0, src_len, sizeof_memop);
	else if (location == 2)
		store_values(arg, BUFF_SIZE / 3, src_len, sizeof_memop);
	else if (location == 3)
		store_values(arg, 2 * BUFF_SIZE / 3,
				src_len, sizeof_memop);
	if (location == 1 || location == 2 || location == 3)
		return ;
	else if (location == 4)
		print(arg, location);
	else
	{
		set_get_return(write(1, &g_final_str, g_bytes_in_final_str)
				+ set_get_return(0));
		g_bytes_in_final_str = 0;
	}
	pthread_mutex_unlock(&mutex);
}
