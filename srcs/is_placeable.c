/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 02:18:35 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 03:28:18 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	is_placeable_continued(t_sqrt **board, t_piece pc, t_point o)
{
	int		x;
	int		y;
	float	possession;
	int		mixed;

	mixed = 0;
	y = pc.free_lines - 1;
	while (++y < pc.y_max + pc.free_lines)
	{
		x = pc.free_columns - 1;
		while (++x < pc.x_max + pc.free_columns)
		{
			possession = board[o.y + y - pc.free_lines]
				[o.x + x - pc.free_columns].possession;
			if (pc.layout[y][x] == 1)
			{
				if (possession == P1)
					mixed++;
				else if (possession == P2 || mixed > 1)
					return (0);
			}
		}
	}
	return ((mixed == 1));
}

int			is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
{
	if (pc.x_max + pc.free_columns > gs.x_max - o.x
		|| pc.y_max + pc.free_lines > gs.y_max - o.y)
		return (0);
	return (is_placeable_continued(board, pc, o));
}
