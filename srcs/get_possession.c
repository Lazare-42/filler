/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/25 23:34:38 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	print_board_old(int x_max, int y_max, t_sqrt **board);

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

void    board_distance_update_1(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	y = 0;
	while (y < gs.y_max)
	{
		x = 1;
		while (x < gs.x_max)
		{
			p1_d_tmp = board[y][x - 1].p1_distance + 1;
			p2_d_tmp = board[y][x - 1].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
			{
				//printf("maj"); fflush(stdout);
				board[y][x].p1_distance = p1_d_tmp;
			}
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
			{
				//printf("maj"); fflush(stdout);
				board[y][x].p2_distance = p2_d_tmp;
			}
			x++;
		}
		y++;
	}
}

void    board_distance_update_2(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	x = gs.x_max - 1;
	while (x >= 0)
	{
		y = 1;
		while (y < gs.y_max)
		{
			p1_d_tmp = board[y - 1][x].p1_distance + 1;
			p2_d_tmp = board[y - 1][x].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y++;
		}
		x--;
	}
}

void    board_distance_update_3(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	y = gs.y_max - 1;
	while (y >= 0)
	{
		x = gs.x_max - 2;
		while (x >= 0)
		{
			//printf("y: %d x: %d\n", y, x); fflush(stdout);
			p1_d_tmp = board[y][x + 1].p1_distance + 1;
			p2_d_tmp = board[y][x + 1].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
			{
				board[y][x].p1_distance = p1_d_tmp;
			}
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
			{
				board[y][x].p2_distance = p2_d_tmp;
			}
			x--;
		}
		y--;
	}
}

void    board_distance_update_4(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	x = 0;
	while (x < gs.x_max)
	{
		y = gs.y_max - 2;
		while (y >= 0)
		{
			p1_d_tmp = board[y + 1][x].p1_distance + 1;
			p2_d_tmp = board[y + 1][x].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y--;
		}
		x++;
	}
}

void    board_distance_update_5(t_sqrt **board, t_filler gs)
{
	int     x;
	int     y;
	int     p1_d_tmp;
	int     p2_d_tmp;
	float   possession;

	y = 1;
	while (y < gs.y_max)
	{
		x = 1;
		while (x < gs.x_max)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y - 1][x - 1].p1_distance + 2;
			p2_d_tmp = board[y - 1][x - 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x++;
		}
		y++;
	}
}

void    board_distance_update_6(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float   possession;

	x = gs.x_max - 2;
	while (x >= 0)
	{
		y = 1;
		while (y < gs.y_max)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y - 1][x + 1].p1_distance + 2;
			p2_d_tmp = board[y - 1][x + 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y++;
		}
		x--;
	}
}

void    board_distance_update_7(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float   possession;

	y = gs.y_max - 2;
	while (y >= 0)
	{
		x = gs.x_max - 2;
		while (x >= 0)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y + 1][x + 1].p1_distance + 2;
			p2_d_tmp = board[y + 1][x + 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x--;
		}
		y--;
	}
}

void    board_distance_update_8(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float   possession;

	x = 1;
	while (x < gs.x_max)
	{
		y = gs.y_max - 2;
		while (y >= 0)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y + 1][x - 1].p1_distance + 2;
			p2_d_tmp = board[y + 1][x - 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y--;
		}
		x++;
	}
}

void    board_possession_update(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p2_d_tmp;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			p2_d_tmp = board[y][x].p2_distance;
			board[y][x].possession = (float)((float)p2_d_tmp
					/ (float)((float)p2_d_tmp + (float)board[y][x].p1_distance));
			x++;
		}
		y++;
	}
}

void    board_distance_reset(t_sqrt **board, t_filler gs)
{
	int		x;
	int		y;
	float	possession;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
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

void    board_update(t_sqrt **board, t_filler gs)
{
	int i;
	i = 0;
	board_distance_reset(board, gs);
	while (i++ < 2)
	{
		board_distance_update_1(board, gs);
		board_distance_update_2(board, gs);
		board_distance_update_3(board, gs);
		board_distance_update_4(board, gs);
		board_distance_update_5(board, gs);
		board_distance_update_6(board, gs);
		board_distance_update_7(board, gs);
		board_distance_update_8(board, gs);
	}
	board_possession_update(board, gs);
}

void    board_print(t_sqrt **board, t_filler gs)
{
	printf("BOARD_PRINT\n"); fflush(stdout);
	int x;
	int y;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			printf("%4.f ", board[y][x].p2_distance);
			//printf("%3.f%% ", board[y][x].possession * 100);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
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

float   score_update_for_p2(t_sqrt ***board_cpy, float *high_score, t_filler gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, gs);
	//printf("score = %.f hscore = %.f\n", score, *high_score); fflush(stdout);
	if (score < *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
}

float   score_update(t_sqrt ***board_cpy, float *high_score, t_filler gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, gs);
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
	y = pc.free_columns;
	while (y < pc.y_max)
	{
		x = pc.free_lines;
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
			//printf("%.f ", possession); fflush(stdout);
			printf("%.f", possession); fflush(stdout);
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
		printf("\n"); fflush(stdout);
		y++;
	}
	//printf("mixed: %d\n", mixed); fflush(stdout);
	return ((mixed == 1));
}

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

t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler gs)
{
	t_point pt;
	t_point memo;
	float   high_score;

	pt.y = -1;
	high_score = 0;
	while (++pt.y < gs.y_max)
	{
		pt.x = -1;
		while (++pt.x < gs.x_max)
		{
			if (is_placeable(board, pc, pt, gs))
			{
				//printf("placeable - x: %d, y: %d\n", pt.x, pt.y); fflush(stdout);
				board_to_board(board, board_cpy, gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
				{
					//printf("new best position - score: %.f\n", high_score); fflush(stdout);
					memo.x = pt.x;
					memo.y = pt.y;
					return (memo);
				}
			}
		}
	}
	return (memo);
}

t_point get_best_position_for_p2(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler gs)
{
	t_point pt;
	t_point memo;
	float   high_score;

	pt.y = -1;
	high_score = gs.x_max * gs.y_max;
	while (++pt.y < gs.y_max)
	{
		pt.x = -1;
		while (++pt.x < gs.x_max)
		{
			if (is_placeable_for_p2(board, pc, pt, gs))
			{
				//printf("placeable - x: %d, y: %d\n", pt.x, pt.y); fflush(stdout);
				board_to_board(board, board_cpy, gs);
				piece_write_for_p2(board_cpy, pc, pt);
				if (score_update_for_p2(board_cpy, &high_score, gs))
				{
					//printf("new best position - score: %.2f\n", high_score); fflush(stdout);
					memo.x = pt.x;
					memo.y = pt.y;
				}
			}
		}
	}
	return (memo);
}

void		boundary_draw_old(t_sqrt **board, t_filler filler)
{
	//	printf("DRAW IN\n"); fflush(stdout);
	t_point	pt;
	float	possession;

	pt.y = 0;
	while (pt.y < filler.y_max)
	{
		pt.x = 0;
		while (pt.x < filler.x_max)
		{
			possession = board[pt.y][pt.x].possession;
			//printf("X: %d Y: %d Possession: %.2f\n", pt.x, pt.y, possession); fflush(stdout);
			if (possession != P1 && possession != P2)
				board[pt.y][pt.x].possession = get_possession(board, pt, filler);
			//			printf("Possession: %.2f\n", possession); fflush(stdout);
			//`			print_board_old(filler.x_max, filler.y_max, board);
			//			getchar();
			pt.x++;
		}
		pt.y++;
	}
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
			if (possession == P1 || possession == P2)
				distance_update_from_point(board, pt, filler, (possession < 0) * 2 - 1);
			pt.x++;
		}
		pt.y++;
	}
	possession_update(board, filler);
}

void		boundary_draw_new(t_sqrt **board, t_filler f)
{
	//board_print(*board, f);
	//board_print(*board, f);
	board_update(board, f);
	//board_print(*board, f);
}
