/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_update_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:11:10 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 00:30:13 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void    board_distance_reset(t_sqrt **board, t_filler gs)
{
	int			x;
	int			y;
	float		possession;
	const int	gs_y_max = gs.y_max;
	const int	gs_x_max = gs.x_max;

	y = 0;
	while (y < gs_y_max)
	{
		x = 0;
		while (x < gs_x_max)
		{
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
			{
				board[y][x].p1_distance = 100000;
				board[y][x].p2_distance = 100000;
			}
			x++;
		}
		y++;
	}
}

void    board_update(t_sqrt **board, t_filler *gs)
{
	int i;
	i = 0;
	board_distance_reset(board, *gs);
	while (i++ < 1)
	{
		board_distance_update_1(board, *gs);
		board_distance_update_2(board, *gs);
		board_distance_update_3(board, *gs);
		board_distance_update_4(board, *gs);
		board_distance_update_5(board, *gs);
		board_distance_update_6(board, *gs);
		board_distance_update_7(board, *gs);
		board_distance_update_8(board, *gs);
	}
	board_possession_update(board, gs);
}

void    board_to_board(t_sqrt **src, t_sqrt ***dest, t_filler gs)
{
	int     x;
	int     y;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			(*dest)[y][x].possession = src[y][x].possession;
			(*dest)[y][x].p1_distance = src[y][x].p1_distance;
			(*dest)[y][x].p2_distance = src[y][x].p2_distance;
			x++;
		};
		y++;
	}
}
