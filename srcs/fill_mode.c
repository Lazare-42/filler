/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:18:37 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 03:24:31 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		placeable_mask_continued(t_arg all, t_point o, t_filler gs, int y)
{
	int		x;
	float	possession;
	int		mixed;

	mixed = 0;
	while (++y < all.pc.y_max + all.pc.free_lines)
	{
		x = all.pc.free_columns - 1;
		while (++x < all.pc.x_max + all.pc.free_columns)
		{
			if (all.pc.layout[y][x] == 1)
			{
				if (gs.mask[(o.y + y - all.pc.free_lines) % 16]
						[(o.x + x - all.pc.free_columns) % 16] == 1)
					return (0);
				possession = all.board[o.y + y - all.pc.free_lines]
					[o.x + x - all.pc.free_columns].possession;
				if ((possession == P2 || mixed > 1))
					return (0);
				else if (possession == P1)
					mixed++;
			}
		}
	}
	return ((mixed == 1));
}

int		is_placeable_with_mask(t_sqrt **board,
		t_piece pc, t_point o, t_filler gs)
{
	int		y;
	t_arg	all;

	all.pc = pc;
	all.board = board;
	if (pc.x_max + pc.free_columns > gs.x_max - o.x
			|| pc.y_max + pc.free_lines > gs.y_max - o.y)
		return (0);
	y = pc.free_lines - 1;
	return (placeable_mask_continued(all, o, gs, y));
}

t_point	get_best_position_fill(t_sqrt **board, t_piece pc, t_filler *gs)
{
	t_point			pt;
	t_point			memo;
	float			high_score;

	memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	while (++pt.y < gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < gs->x_max)
		{
			if (is_placeable_with_mask(board, pc, pt, *gs))
				return (pt);
		}
	}
	gs->fill_mode = 2;
	return (memo);
}

t_point	get_best_position_fill_and_win(t_sqrt **board, t_piece pc, t_filler *gs)
{
	t_point			pt;
	t_point			memo;
	float			high_score;

	memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = gs->y_max;
	while (--pt.y > 0)
	{
		pt.x = gs->x_max;
		while (--pt.x > 0)
		{
			if (is_placeable(board, pc, pt, *gs))
				return (pt);
		}
	}
	return (memo);
}
