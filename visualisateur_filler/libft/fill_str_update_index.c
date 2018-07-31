/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_update_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:31:16 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 19:00:28 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	update_str(t_str *argument, void *to_cpy, int mem_op_size)
{
	int tmp;

	tmp = 0;
	if (argument->position + mem_op_size >= BUFF_SIZE)
		launch_string_print(NULL, 0, argument, 1);
	while (mem_op_size >= BUFF_SIZE)
	{
		mem_op_size -= BUFF_SIZE;
		ft_memcpy(argument->str + argument->position, to_cpy, BUFF_SIZE);
		launch_string_print(NULL, 0, argument, 1);
	}
	ft_memcpy(argument->str + argument->position, to_cpy, mem_op_size);
	argument->position += mem_op_size;
}
