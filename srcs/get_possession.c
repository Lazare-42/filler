/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/17 00:21:15 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

static void		position_update(t_point *position, t_direction direction)
{
	int	x_diff;
	int	y_diff;

	x_diff = 0;
	y_diff = 0;
	if (direction == up)
		y_diff--;
	else if (direction == right)
		x_diff++;
	else if (direction == down)
		y_diff++;
	else if (direction == left)
		x_diff--;
	position->x += x_diff;
	position->y += y_diff;
}

static void		position_init(t_point *position, int x, int y)
{
	position->x = x;
	position->y = y;
}

static float	get_possession(t_sqrt **board, t_point o, t_filler filler)
{
	float		possession;
	t_point		pt;
	t_direction	direction;
	int			i;
	int			i_lim;
	float		distance_p1;
	float		distance_p2;
	int			time;

	(void)board;
	(void)filler;
	i_lim = 1;
	position_init(&pt, o.x, o.y);
	distance_p1 = -1;
	distance_p2 = -1;
	while (distance_p1 < 0 || distance_p2 < 0)
	{
		time = 0;
		while (time < 2)
		{
			i = 0;
			while (i < i_lim)
			{
				position_update(&pt, direction);
//				printf("POSITION x: %d - y: %d\n", pt.x, pt.y); fflush(stdout);
				if (pt.x >= 0 && pt.x < filler.x_max && pt.y >= 0 && pt.y < filler.y_max)
				{
					if (board[pt.y][pt.x].possession == 1)
					{
						distance_p1 = i + 1;
					}
					else if (board[pt.y][pt.x].possession == 0)
					{
						distance_p2 = i + 1;
					}
				}
				i++;
			}
			time++;
			direction = (direction + 1) % 4;
		}
		i_lim++;
	}
	possession = distance_p1 / (distance_p1 + distance_p2);
	return (possession);
}

void		boundary_draw(t_sqrt **board, t_filler filler)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < filler.y_max)
	{
		pt.x = 0;
		while (pt.x < filler.x_max)
		{
			if (board[pt.y][pt.x].possession > 0 && board[pt.y][pt.x].possession < 1)
				board[pt.y][pt.x].possession = get_possession(board, pt, filler);
			print_board(filler.x_max, filler.y_max, board);
			pt.x++;
		}
		pt.y++;
	}
}
