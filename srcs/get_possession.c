/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:33:23 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 02:25:21 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <pthread.h>

void	piece_write(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
	int		x;
	int		y;
	int		fl;
	int		fc;

	y = pc.free_lines;
	fl = pc.free_lines;
	fc = pc.free_columns;
	while (y < pc.y_max + pc.free_lines)
	{
		x = pc.free_columns;
		while (x < pc.x_max + pc.free_columns)
		{
			if (pc.layout[y][x] == 1)
			{
				(*board_cpy)[o.y + y - fl][o.x + x - fc].possession = 1;
				(*board_cpy)[o.y + y - fl][o.x + x - fc].p1_distance = 0;
				(*board_cpy)[o.y + y - fl][o.x + x - fc].p2_distance = 99999;
			}
			x++;
		}
		y++;
	}
}

void	placeable_operations(t_thread_arg *block, t_point pt,
		t_memo *memo, float *high_score)
{
	board_to_board(block->info.board, &(block->board_cpy), *(block->info.gs));
	piece_write(&(block->board_cpy), block->info.pc, pt);
	if (score_update(&(block->board_cpy), high_score, (block->info.gs)))
	{
		memo->memo = t_point_init(pt.x, pt.y);
		memo->score = *high_score;
	}
}

void	*get_best_pos_thread(void *arg)
{
	t_point			pt;
	t_memo			memo;
	float			high_score;
	t_thread_arg	*block;
	int				placeable;

	memo.memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	placeable = 0;
	block = arg;
	while (++pt.y < block->info.gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < block->info.gs->x_max)
		{
			if (((++placeable + 1) % CORE_NUMBER) == (block->index)
					&& is_placeable(block->info.board, block->info.pc, pt,
						*(block->info.gs)))
				placeable_operations(block, pt, &memo, &high_score);
		}
		block->memo = memo;
	}
	return (NULL);
}

t_point	launch_threads(t_thread_arg block[CORE_NUMBER], t_point memo)
{
	int				y;
	pthread_t		threads[CORE_NUMBER];
	void			*arg;

	y = -1;
	while (++y < CORE_NUMBER)
	{
		arg = &block[y];
		if (pthread_create(&threads[y], NULL, get_best_pos_thread, (arg)))
			ft_myexit("thread creation error");
	}
	y = -1;
	while (++y < CORE_NUMBER)
		pthread_join(threads[y], NULL);
	memo = get_best_score_from_tab(block);
	return (memo);
}

t_point	get_best_position(t_thread_arg block[CORE_NUMBER])
{
	t_point			memo;

	memo.x = 0;
	memo.y = 0;
	if (block[0].info.gs->fill_mode == 0)
		memo = launch_threads(block, memo);
	else
		memo = get_best_position_fill(
		block[0].info.board, block[0].info.pc, block[0].info.gs);
	if (block[0].info.gs->fill_mode == 2)
		memo = get_best_position_fill_and_win(
		block[0].info.board, block[0].info.pc, block[0].info.gs);
	if (!is_placeable(block[0].info.board,
		block[0].info.pc, memo, *(block[0].info.gs)))
		block[0].info.gs->game_over = 1;
	return (memo);
}
