/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/18 00:14:26 by jboursal         ###   ########.fr       */
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

static int		ft_filler_abs(int x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

static float	get_possession(t_sqrt **board, t_point o, t_filler filler)
{
	t_point		pt;
	t_direction	direction;
	int			i;
	int			i_lim;
	float		distance_p1;
	float		distance_p2;
	int			time;

	i_lim = 1;
	position_init(&pt, o.x, o.y);
	distance_p1 = -1;
	distance_p2 = -1;
	direction = up;
	while (distance_p1 < 0 || distance_p2 < 0)
	{
		time = 0;
		while (time++ < 2)
		{
			i = 0;
			while (i++ < i_lim)
			{
				position_update(&pt, direction);
				//printf("position px %d py %d\n", pt.x, pt.y);
				if (pt.x >= 0 && pt.x < filler.x_max && pt.y >= 0 && pt.y < filler.y_max)
				{
					if (board[pt.y][pt.x].possession == 1 && distance_p1 == -1)
					{
						distance_p1 = (ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)) * 2 + i_lim / 2;
						//printf("distance p1: %d - px %d - py %d - pox %d - poy %d\n", (int)distance_p1, pt.x, pt.y, o.x, o.y);
					}
					else if (board[pt.y][pt.x].possession == 0 && distance_p2 == -1)
					{
						distance_p2 = (ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)) * 2 + i_lim / 2;
						//printf("distance p2: %d - px %d - py %d - pox %d - poy %d\n", (int)distance_p2, pt.x, pt.y, o.x, o.y);

					}
				}
			}
			direction = (direction + 1) % 4;
		}
		i_lim++;
	}
	return (distance_p2 / (distance_p1 + distance_p2));
}

void		boundary_draw(t_sqrt **board, t_filler filler)
{
	t_point	pt;
	float	possession;

	pt.y = 0;
	while (pt.y < filler.y_max)
	{
		pt.x = 0;
		while (pt.x < filler.x_max)
		{
			possession = board[pt.y][pt.x].possession;
			if (possession > 0 && possession < 1)
				board[pt.y][pt.x].possession = get_possession(board, pt, filler);
			//print_board(filler.x_max, filler.y_max, board);
			//getchar();
			pt.x++;
		}
		pt.y++;
	}
}
