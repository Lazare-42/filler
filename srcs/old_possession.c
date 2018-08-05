/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/05 19:23:01 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <sys/sysctl.h>
#include <pthread.h>

void	print_board_old(int x_max, int y_max, t_sqrt **board);


/*
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
//				printf("position px %d py %d\n", pt.x, pt.y);
if (pt.x >= 0 && pt.x < filler.x_max && pt.y >= 0 && pt.y < filler.y_max)
{
if (board[pt.y][pt.x].possession == P1 && distance_p1 == -1)
{
distance_p1 = (ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)) * 2;
//						printf("distance p1: %d - px %d - py %d - pox %d - poy %d\n", (int)distance_p1, pt.x, pt.y, o.x, o.y);
}
else if (board[pt.y][pt.x].possession == P2 && distance_p2 == -1)
{
distance_p2 = (ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)) * 2;
//						printf("distance p2: %d - px %d - py %d - pox %d - poy %d\n", (int)distance_p2, pt.x, pt.y, o.x, o.y);
}
}
}
direction = (direction + 1) % 4;
}
i_lim++;
}
return (distance_p1 / (distance_p1 + distance_p2));
}
*/

t_point t_point_init(int x, int y)
{
	t_point point;
	point.x = x;
	point.y = y;
	return (point);
}

/*
   void	possession_update_from_point(t_sqrt **board, t_point o, t_filler filler, int player_side)
   {
   t_point		pt;
   float		distance;

   pt.y = 0;
   while (pt.y < filler.y_max)
   {
   pt.x = 0;
   while (pt.x < filler.x_max)
   {
   if (board[pt.y][pt.x].possession != P1 && board[pt.y][pt.x].possession != P2)
   {
   if (player_side < 0 && board[pt.y][pt.x].p1_distance >
   (distance = ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)))
   board[pt.y][pt.x].p1_distance = distance;
   else if (player_side > 0 && board[pt.y][pt.x].p2_distance >
   (distance = ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)))
   board[pt.y][pt.x].p2_distance = distance;
   }
   pt.x++;
   }
   pt.y++;
   }
   }
   */

/*
   void	distance_update_from_point(t_sqrt **board, t_point o, t_filler filler, int player_side)
   {
   int			x;
   int			y;
   float		distance;
   float		possession;

   y = 0;
   while (y < filler.y_max)
   {
   x = 0;
   while (x < filler.x_max)
   {
   possession = board[y][x].possession;
   if (possession != P1 && possession != P2)
   {
   distance = ft_filler_abs(y - o.y) + ft_filler_abs(x - o.x);
   if (player_side < 0  && board[y][x].p1_distance > distance)
   board[y][x].p1_distance = distance;
   else if (player_side > 0 && board[y][x].p2_distance > distance)
   board[y][x].p2_distance = distance;
   }
   x++;
   }
   y++;
   }
   }
   */

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
/*
   void    board_print(t_sqrt **board, t_filler gs)
   {
   printf("BOARD_PRINT\n"); fflush(stdout);
   int x;
   int y;
   float possession;

   y = 0;
   while (y < gs.y_max)
   {
   x = 0;
   while (x < gs.x_max)
   {
//	printf("%3.f ", board[y][x].p2_distance);
possession = board[y][x].possession;
if (possession == P1)
printf("  O  ");
else if (possession == P2)
printf("  X  ");
else
printf("%3.f%% ", possession * 100);
x++;
}
printf("\n");
y++;
}
printf("\n");
}
*/
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
/*
   int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
   {
   int     x;
   int     y;
   float   possession;
   int		mixed;

   mixed = 0;
   if (pc.x_max > gs.x_max - o.x || pc.y_max > gs.y_max - o.y)
   return (0);
   y = pc.free_columns;
   while (y < pc.y_max)
   {
   x = pc.free_lines;
   while (x < pc.x_max)
   {
//printf("%.f ", possession); fflush(stdout);
//printf("%.f", possession); fflush(stdout);
if (pc.layout[y][x] == 1 && gs.mask[(o.y + y) % 7][(o.x + x) % 7] == 0)
{
possession = board[o.y + y][o.x + x].possession;
if (possession == P1)
mixed++;
else if (possession == P2)
return (0);
}
else if (pc.layout[y][x] == 1 && gs.mask[(o.y + y) % 7][(o.x + x) % 7] == 1)
return (0);
x++;
}
//printf("\n"); fflush(stdout);
y++;
}
//printf("mixed: %d\n", mixed); fflush(stdout);
return ((mixed == 1));
}
*/


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

void	get_best_position_std_1(void *arg)
{
	t_point			pt;
	t_memo			memo;
	float			high_score;
	t_arg			*all;
	int				placeable;

	all = arg;
	memo.memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	placeable = 0;
	while (++pt.y < all->gs.y_max)
	{
		pt.x = -1;
		while (++pt.x < all->gs.x_max)
		{
			if (++placeable % 4 == 1 && is_placeable(all->board, all->pc, pt, all->gs))
			{
				board_to_board(all->board, &(all->board_cpy[0]), all->gs);
				piece_write(&(all->board_cpy[0]), all->pc, pt);
				if (score_update(&(all->board_cpy[0]), &high_score, &(all->gs)))
				{
					memo.memo = t_point_init(pt.x, pt.y);
					memo.score = high_score;
				}
			}
		}
		all->memo[0] = memo;
	}
}

void	get_best_position_std_2(void *arg)
{
	t_point			pt;
	t_memo			memo;
	float			high_score;
	t_arg			*all;
	int				placeable;

	all = arg;
	memo.memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	placeable = 0;
	while (++pt.y < all->gs.y_max)
	{
		pt.x = -1;
		while (++pt.x < all->gs.x_max)
		{
			if (++placeable % 4 == 2 && is_placeable(all->board, all->pc, pt, all->gs))
			{
				board_to_board(all->board, &(all->board_cpy[1]), all->gs);
				piece_write(&(all->board_cpy[1]), all->pc, pt);
				if (score_update(&(all->board_cpy[1]), &high_score, &(all->gs)))
				{
					memo.memo = t_point_init(pt.x, pt.y);
					memo.score = high_score;
				}
			}
		}
		all->memo[1] = memo;
	}
}

void	get_best_position_std_3(void *arg)
{
	t_point			pt;
	t_memo			memo;
	float			high_score;
	t_arg			*all;
	int				placeable;

	all = arg;
	memo.memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	placeable = 0;
	while (++pt.y < all->gs.y_max)
	{
		pt.x = -1;
		while (++pt.x < all->gs.x_max)
		{
			if (++placeable % 4 == 3 && is_placeable(all->board, all->pc, pt, all->gs))
			{
				board_to_board(all->board, &(all->board_cpy[2]), all->gs);
				piece_write(&(all->board_cpy[2]), all->pc, pt);
				if (score_update(&(all->board_cpy[2]), &high_score, &(all->gs)))
				{
					memo.memo = t_point_init(pt.x, pt.y);
					memo.score = high_score;
				}
			}
		}
		all->memo[2] = memo;
	}
}

void	get_best_position_std_4(void *arg)
{
	t_point			pt;
	t_memo			memo;
	float			high_score;
	t_arg			*all;
	int				placeable;

	all = arg;
	memo.memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	placeable = 0;
	while (++pt.y < all->gs.y_max)
	{
		pt.x = -1;
		while (++pt.x < all->gs.x_max)
		{
			if (++placeable % 4 == 0 && is_placeable(all->board, all->pc, pt, all->gs))
			{
				board_to_board(all->board, &(all->board_cpy[3]), all->gs);
				piece_write(&(all->board_cpy[3]), all->pc, pt);
				if (score_update(&(all->board_cpy[3]), &high_score, &(all->gs)))
				{
					memo.memo = t_point_init(pt.x, pt.y);
					memo.score = high_score;
				}
			}
		}
	}
	all->memo[3] = memo;
}

t_point	get_best_score_from_tab(t_arg *all)
{
	t_point	memo;
	int		i;
	float	score_tmp;

	score_tmp = 0;
	i = -1;
	while (++i < 4)
	{
		if (score_tmp < all->memo[i].score)
		{
			memo = all->memo[i].memo;
			score_tmp = all->memo[i].score;
		}
	}
	return (memo);
}

t_point get_best_position(t_arg *all, t_filler *gs)
{
	t_point			memo;
	void			*arg;
	pthread_t		threads[4];
	int				y;

	memo.x = 0;
	memo.y = 0;
	arg = all;
	y = -1;
	all->thread_nbr = 1;
	if (pthread_create(&threads[0], NULL, (void*)get_best_position_std_1, (arg)))
		ft_myexit("thread creation error");
	if (pthread_create(&threads[1], NULL, (void*)get_best_position_std_2, (arg)))
		ft_myexit("thread creation error");
	if (pthread_create(&threads[2], NULL, (void*)get_best_position_std_3, (arg)))
		ft_myexit("thread creation error");
	if (pthread_create(&threads[3], NULL, (void*)get_best_position_std_4, (arg)))
		ft_myexit("thread creation error");
	y = -1;
	while (++y < 4)
		pthread_join(threads[y], NULL);
	memo = get_best_score_from_tab(all);
	if (!is_placeable(all->board, all->pc, memo, *gs))
	{
		gs->game_over = 1;
	}
	return (memo);
}
