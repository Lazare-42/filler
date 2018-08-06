/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_possession.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:14:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 03:27:48 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_point			get_best_score_from_tab(t_thread_arg block[CORE_NUMBER])
{
	t_point	memo;
	int		i;
	float	score_tmp;

	score_tmp = 0;
	i = -1;
	while (++i < CORE_NUMBER)
	{
		if (score_tmp < block[i].memo.score)
		{
			memo = block[i].memo.memo;
			score_tmp = block[i].memo.score;
		}
	}
	return (memo);
}

void			board_possession_update(t_sqrt **board, t_filler *gs)
{
	int				x;
	int				y;
	float			p2_d_tmp;
	float			possession;
	int				time;

	time = 0;
	y = -1;
	gs->fill_mode = 1;
	while (++y < gs->y_max)
	{
		x = -1;
		while (++x < gs->x_max)
		{
			p2_d_tmp = board[y][x].p2_distance;
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
				board[y][x].possession = p2_d_tmp
					/ (p2_d_tmp + board[y][x].p1_distance);
			if (possession < 0.92 && possession > 0.08)
				time++;
			if (time > (gs->x_max * gs->y_max) / 20)
				gs->fill_mode = 0;
		}
	}
}

static	float	board_score_calc(t_sqrt **board, t_filler gs)
{
	float	score;
	int		x;
	int		y;

	score = 0;
	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			score += board[y][x].possession;
			x++;
		}
		y++;
	}
	return (score);
}

float			score_update(t_sqrt ***board_cpy, float *high_score,
		t_filler *gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, *gs);
	if (score > *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
}
