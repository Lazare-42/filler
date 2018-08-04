/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/04 23:24:19 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <sys/sysctl.h>
#include <pthread.h>

void	print_board_old(int x_max, int y_max, t_sqrt **board);



t_point t_point_init(int x, int y)
{
	t_point point;
	point.x = x;
	point.y = y;
	return (point);
}

void	possession_update(t_sqrt **board, t_filler filler)
{
	int			x;
	int			y;
	float		p2_d;
	float		possession;

	y = 0;
	while (y < filler.y_max)
	{
		x = 0;
		while (x < filler.x_max)
		{
			p2_d = board[y][x].p2_distance;
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
				board[y][x].possession = p2_d / (p2_d + board[y][x].p1_distance);
			x++;
		}
		y++;
	}
}

void    board_possession_update(t_sqrt **board, t_filler *gs)
{
	int				x;
	int				y;
	float			p2_d_tmp;
	float			possession;
	int		time;
	const int		gs_y_max = gs->y_max;
	const int		gs_x_max = gs->x_max;

	time = 0;
	y = 0;
	gs->fill_mode = 1;
	while (y < gs_y_max)
	{
		x = 0;
		while (x < gs_x_max)
		{
			p2_d_tmp = board[y][x].p2_distance;
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
			board[y][x].possession = p2_d_tmp / (p2_d_tmp + board[y][x].p1_distance);
			if (possession < 0.8 && possession > 0.2)
			  time++;
			  if (time > (gs->x_max * gs->y_max) / 20)
			  gs->fill_mode = 0;
			x++;
		}
		y++;
	}
}

void    board_distance_reset(t_sqrt **board, t_filler gs)
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

float   board_score_calc(t_sqrt **board, t_filler gs)
{
	float score;
	int x;
	int y;

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


float   score_update(t_sqrt ***board_cpy, float *high_score, t_filler *gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, *gs);
	//printf("score = %.f hscore = %.f\n", score, *high_score); fflush(stdout);
	if (score > *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
}

int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
{
	int     x;
	int     y;
	float   possession;
	int		mixed;

	mixed = 0;
	if (pc.x_max + pc.free_columns > gs.x_max - o.x || pc.y_max + pc.free_lines > gs.y_max - o.y)
		return (0);
	y = pc.free_lines;
	while (y < pc.y_max + pc.free_lines)
	{
		x = pc.free_columns;
		while (x < pc.x_max + pc.free_columns)
		{
			possession = board[o.y + y - pc.free_lines][o.x + x - pc.free_columns].possession;
			if (pc.layout[y][x] == 1)
			{
				if (possession == P1)
					mixed++;
				else if (possession == P2)
					return (0);
				if (mixed > 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	return ((mixed == 1));
}

void     piece_write(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
	int     x;
	int     y;
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
		};
		y++;
	}
}

float     piece_get_score(t_sqrt **board, t_piece pc, t_point o, float lowest_score)
{
	int     x;
	int     y;
	float	score;

	score = 0;
	y = 0;
	while (y < pc.y_max && score < lowest_score)
	{
		x = 0;
		while (x < pc.x_max && score < lowest_score)
		{
			if (pc.layout[y][x] == 1)
			{
				score += board[o.y + y][o.x + x].possession;
			}
			x++;
		};
		y++;
	}
	return (score);
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

t_point get_best_position_from_zone(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs, t_point zone)
{
	t_point			pt;
	t_point			memo;
	float			high_score;
	const int		x_lim = (zone.x + 5 < gs->x_max) ? zone.x + 5 : gs->x_max;
	const int		y_lim = (zone.y + 5 < gs->y_max) ? zone.y + 5 : gs->y_max;

	memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = (zone.y - 5 > -1) ? zone.y - 5 : -1;
	while (++pt.y < y_lim)
	{
		pt.x = (zone.x - 5 > -1) ? zone.x - 5 : -1;
		while (++pt.x < x_lim)
		{
			if (is_placeable(board, pc, pt, *gs))
			{
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
					memo = t_point_init(pt.x, pt.y);
			}
		}
	}
	return (memo);
}

t_point get_best_zone(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			pt;
	t_point			memo;
	float			high_score;
	int				placeable;

	memo = t_point_init(0, 0);
	placeable = OPTI;
	high_score = 0;
	pt.y = -1;
	while (++pt.y < gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < gs->x_max)
		{
			if (is_placeable(board, pc, pt, *gs) && !(++placeable % (OPTI + 1)))
			{
				if (gs->fill_mode == 1)
					return (pt);
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
					memo = t_point_init(pt.x, pt.y);
			}
		}
	}
	return (memo);
}

int		set_get_core_numbers(void)
{
	static int		core_number = 0;
	static size_t	count_len = sizeof(core_number);

	if (!core_number)
		sysctlbyname("hw.logicalcpu", &core_number, &count_len, NULL, 0);
	return (core_number);
}

t_point set_fetch_best_position(t_point memo, float high_score, int set)
{
	static	t_point memo_found;
	static	float	high_score_found = 0;
	pthread_mutex_t mutex;

	pthread_mutex_lock(&mutex);
	if (set == FILL_MODE)
	{
		memo_found = memo;
		high_score_found = FILL_MODE;
	}
	if (set != SET_MEMO)
	{
		high_score_found = 0;
		return (memo_found);
	}
	else if (high_score >= high_score_found)
	{
		high_score_found = high_score;
		memo_found = memo;
	}
	pthread_mutex_unlock(&mutex);
	return (memo_found);
}

void get_best_position_std(void *arg)
{
	t_point			pt;
	t_point			memo;
	float			high_score;
	int				line_to;
	t_arg			*all;

	all = arg;
	high_score = 0;

	/*
	pt.y = all->gs->y_max / set_get_core_numbers();
	line_to = pt.y * all->thread_nbr;
	pt.y = line_to - pt.y - 1;

	if (all->thread_nbr == set_get_core_numbers())
		line_to += all->gs->y_max % set_get_core_numbers();
		*/
	line_to = all->gs->y_max;
	pt.y = -1;
	memo = t_point_init(0, 0);
	while (++pt.y < line_to)
	{
		pt.x = -1;
		while (++pt.x < all->gs->x_max)
		{
			if (is_placeable(all->board, all->pc, pt, *all->gs))
			{
				if (all->gs->fill_mode == 1)
					set_fetch_best_position(pt, 0, FILL_MODE);
				board_to_board(all->board, all->board_cpy, *all->gs);
				piece_write(all->board_cpy, all->pc, pt);
				if (score_update(all->board_cpy, &high_score, all->gs))
				{
					memo = t_point_init(pt.x, pt.y);
					set_fetch_best_position(memo, high_score, SET_MEMO);
				}
			}
		}
	}
}

t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			memo;
	t_arg			all;
	pthread_t		threads[set_get_core_numbers()];
	int				y;
	void			*arg;

	memo.x = 0;
	memo.y = 0;
	all.gs = gs;
	all.pc = pc;
	all.board_cpy = board_cpy;
	all.board = board;
	y = -1;
	arg = &all;
	/*
	if (OPTI)
	{
		memo = get_best_zone(board, board_cpy, pc, gs);
		if (gs->fill_mode)
			memo = get_best_position_from_zone(board, board_cpy, pc, gs, memo);
	}
	else
	get_best_position_std(arg);
	*/
	while (++y < set_get_core_numbers())
	{
		all.thread_nbr = y + 1;
		if (pthread_create(&threads[y], NULL, (void*)get_best_position_std, (arg)))
			ft_myexit("thread creation error");
	}
	y = -1;
	while (++y < set_get_core_numbers())
		pthread_join(threads[y], NULL);
	memo = set_fetch_best_position(memo, 0, 0);
	if (!is_placeable(board, pc, memo, *gs))
		gs->game_over = 1;
	return (memo);
}

void		boundary_draw_new(t_sqrt **board, t_filler *f)
{
	//board_print(*board, f);
	//board_print(*board, f);
	board_update(board, f);
	//board_print(*board, f);
}
