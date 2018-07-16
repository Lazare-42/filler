/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/16 21:25:12 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	position_update(t_point *position, t_direction direction)
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

static void	position_init(t_point *position, int x, int y)
{
	position->x = x;
	position->y = y;
}

float		get_possession(t_sqrt **board, int x, int y)
{
	float		possession;
	t_point		position;
	t_direction	direction;
	int			i;
	int			i_lim;
	int			distance_p1;
	int			distance_p2;
	int			time;

	i_lim = 1;
	position_init(&position, x, y);
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
				position_update(&position, direction);
				if (board[position.y][position.x].possession == 1)
				{
					distance_p1 = i + 1;
				}
				else if (board[position.y][position.x].possession == 0)
				{
					distance_p2 = i + 1;
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
