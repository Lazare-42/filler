/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/01 13:36:09 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	print_board_old(int x_max, int y_max, t_sqrt **board);


static int		ft_filler_abs(int x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

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
	//int		time;
	const int		gs_y_max = gs->y_max;
	const int		gs_x_max = gs->x_max;

	//time = 0;
	y = 0;
	gs->fill_mode = 1;
	while (y < gs_y_max)
	{
		x = 0;
		while (x < gs_x_max)
		{
			p2_d_tmp = board[y][x].p2_distance;
			//possession = board[y][x].possession;
			//if (possession != P1 && possession != P2)
			board[y][x].possession = p2_d_tmp / (p2_d_tmp + board[y][x].p1_distance);
			/*if (possession < 0.8 && possession > 0.2)
			  time++;
			  if (time > (gs->x_max * gs->y_max) / 20)
			  gs->fill_mode = 0;*/
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

float   score_update_for_p2(t_sqrt ***board_cpy, float *high_score, t_filler *gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, *gs);
	//printf("score = %.f hscore = %.f\n", score, *high_score); fflush(stdout);
	if (score < *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
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

int     is_placeable_for_p2(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
{
	int     x;
	int     y;
	float   possession;
	int		mixed;

	mixed = 0;
	if (pc.x_max > gs.x_max - o.x || pc.y_max > gs.y_max - o.y)
		return (0);
	y = 0/*pc.free_columns*/;
	while (y < pc.y_max)
	{
		x = 0/*pc.free_lines*/;
		while (x < pc.x_max)
		{
			possession = board[o.y + y][o.x + x].possession;
			//printf("%.f ", possession); fflush(stdout);
			if (pc.layout[y][x] == 1)
			{
				if (possession == P2)
					mixed++;
				else if (possession == P1)
					return (0);
			}
			x++;
		}
		//printf("\n"); fflush(stdout);
		y++;
	}
	//printf("mixed: %d\n", mixed); fflush(stdout);
	return ((mixed == 1));
}

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
			possession = board[o.y + y][o.x + x].possession;
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
void     piece_write_for_p2(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
	int     x;
	int     y;

	y = 0;
	while (y < pc.y_max)
	{
		x = 0;
		while (x < pc.x_max)
		{
			if (pc.layout[y][x] == 1)
			{
				(*board_cpy)[o.y + y][o.x + x].possession = 0;
				(*board_cpy)[o.y + y][o.x + x].p1_distance = 99999;
				(*board_cpy)[o.y + y][o.x + x].p2_distance = 0;
			}
			x++;
		};
		y++;
	}
}

void     piece_write(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
	int     x;
	int     y;

	y = 0;
	while (y < pc.y_max)
	{
		x = 0;
		while (x < pc.x_max)
		{
			if (pc.layout[y][x] == 1)
			{
				(*board_cpy)[o.y + y][o.x + x].possession = 1;
				(*board_cpy)[o.y + y][o.x + x].p1_distance = 0;
				(*board_cpy)[o.y + y][o.x + x].p2_distance = 99999;
			}
			x++;
		};
		y++;
	}
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

	memo.x = 0;
	memo.y = 0;
	high_score = 0;
	pt.y = (zone.y - 5 > -1) ? zone.y - 5 : -1;
	while (++pt.y < y_lim)
	{
		pt.x = (zone.x - 5 > -1) ? zone.x - 5 : -1;
		while (++pt.x < x_lim)
		{
			if (is_placeable(board, pc, pt, *gs))
			{
				//printf("fill = %d - p2_d = %.f\n", gs->fill_mode, board[pt.y][pt.x].p2_distance); fflush(stdout);
				//if (opti == 2 || board[pt.y][pt.x].p2_distance < 7 || gs->fill_mode == 1)
				//{
				//if (gs->fill_mode == 1)
				//	return (pt);
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
				{
					memo.x = pt.x;
					memo.y = pt.y;
				}
				//}
			}
		}
	}
	//}
return (memo);
}

t_point get_best_zone(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			pt;
	t_point			memo;
	float			high_score;
	int				placeable;

	memo.x = 0;
	memo.y = 0;
	placeable = 0;
	high_score = 0;
	pt.y = -1;
	while (++pt.y < gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < gs->x_max)
		{
			if (!(++placeable % 1) && is_placeable(board, pc, pt, *gs))
			{
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
				{
					memo.x = pt.x;
					memo.y = pt.y;
				}
			}
		}
	}
	return (memo);
}

t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			memo;

	memo.x = 0;
	memo.y = 0;
	memo = get_best_zone(board, board_cpy, pc, gs);
	//memo = get_best_position_from_zone(board, board_cpy, pc, gs, memo);
	return (memo);
}
