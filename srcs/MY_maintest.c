/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 08:27:36 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	boundary_draw_old(t_sqrt **board, t_filler filler);
t_sqrt	**board_random(t_filler game_settings, int nb);
void	print_board_old(int x_max, int y_max, t_sqrt **board);
void	boundary_draw_new(t_sqrt **board, t_filler *f);
void    board_cpy_reset(t_sqrt **board, t_sqrt ***board_cpy, t_filler game_settings);
int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs);
float   board_score_calc(t_sqrt **board, t_filler gs);
t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs);
t_point get_best_position_for_p2(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs);
void    board_print(t_sqrt **board, t_filler gs);
void    piece_write(t_sqrt ***board, t_piece pc, t_point o);
void    piece_write_for_p2(t_sqrt ***board, t_piece pc, t_point o);
/*
static void	mask_init(t_filler gs)
{
	int	y;
	int	x;

	float	model[7][7] = 
	{
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1}
	};
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 7)
		{
				gs.mask[y][x] = model[y][x];
			x++;
			printf("%.f ", model[y][x]);
			//printf("%.f ", gs.mask[y][x]);
		}
		printf("\n");
		y++;
	}
}*/

static float	**mask_init(void)
{
	int	y;
	int	x;
	float	**ret;
	float	model[7][7] = 
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,1,1,1,0,0},
		{0,0,1,1,1,0,0},
		{0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	};

	y = 0;
	ret = (float **)malloc(sizeof(float *) * 7);
	while (y < 7)
	{
		ret[y] = (float *)malloc(sizeof(float) * 7);
		x = 0;
		while (x < 7)
		{
			ret[y][x] = model[y][x];
			printf("%.f ", ret[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (ret);
}

static int **layout_init(char layout[3][3])
{
	int	y;
	int	x;
	int	**ret;

	y = 0;
	ret = (int **)malloc(sizeof(int *) * 3);
	while (y < 3)
	{
		ret[y] = (int *)malloc(sizeof(int) * 3);
		x = 0;
		while (x < 3)
		{
			if (layout[y][x] == '*')
				ret[y][x] = 1;
			else
				ret[y][x] = 0;
			x++;
		}
		y++;
	}
	return (ret);
}

int	main(void)
{
	t_sqrt		**board;
	t_sqrt		**board_cpy;
	t_filler	f;
	int			i;
	float		score;
	t_point		point;
	t_piece		pc;
	t_point		best_position;
	char		pc_layout[3][3] = 
	{
		{'*','*','.'},
		{'.','*','.'},
		{'.','.','.'}
	};

	pc.layout = layout_init(pc_layout);
	f.mask = mask_init();
	pc.x_max = 2;
	pc.y_max = 2;
	pc.free_columns = 0;
	pc.free_lines = 0;
	point.x = 2;
	point.y = 6;

	f.x_max = 20;
	f.y_max = 20;
	board = board_random(f, 0);
	board_cpy = board_random(f, 0);

	//printf("BOARD\n"); fflush(stdout);
	//print_board_old(f.x_max, f.y_max, board);
/*	printf("BOARD CPY\n"); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board_cpy);
	board_cpy_reset(board, &board_cpy, f);
	printf("BOARD\n"); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board);
	printf("BOARD CPY\n"); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board_cpy);*/
	//printf("is_placeable = %d\n", is_placeable(board, pc, point, f)); fflush(stdout);

	//board[0][0].possession = P2;
	//board[0][0].p1_distance = 500;
	//board[0][0].p2_distance = 0;
	/*board[5][0].possession = P1;
	board[5][0].p1_distance = 0;
	board[5][0].p2_distance = 500;
	board[5][1].possession = P1;
	board[5][1].p1_distance = 0;
	board[5][1].p2_distance = 500;
	board[5][2].possession = P1;
	board[5][2].p1_distance = 0;
	board[5][2].p2_distance = 500;
	board[4][2].possession = P1;
	board[4][2].p1_distance = 0;
	board[4][2].p2_distance = 500;
	board[3][2].possession = P1;
	board[3][2].p1_distance = 0;
	board[3][2].p2_distance = 500;
	board[2][2].possession = P1;
	board[2][2].p1_distance = 0;
	board[2][2].p2_distance = 500;
	board[1][2].possession = P1;
	board[1][2].p1_distance = 0;
	board[1][2].p2_distance = 500;*/
	/*board[0][2].possession = P1;
	board[0][2].p1_distance = 0;
	board[0][2].p2_distance = 500;*/

	/*board[8][8].possession = P2;
	board[8][8].p1_distance = 500;
	board[8][8].p2_distance = 0;
	board[0][15].possession = P2;
	board[0][15].p1_distance = 500;
	board[0][15].p2_distance = 0;*/
	board[0][0].possession = P2;
	board[0][0].p1_distance = 500;
	board[0][0].p2_distance = 0;
	board[19][19].possession = P1;
	board[19][19].p1_distance = 0;
	board[19][19].p2_distance = 500;
	/*board[19][19].possession = P1;
	board[19][19].p1_distance = 0;
	board[19][19].p2_distance = 500;*/
	/*board[0][15].possession = P1;
	board[0][15].p1_distance = 0;
	board[0][15].p2_distance = 500;
	board[15][0].possession = P1;
	board[15][0].p1_distance = 0;
	board[15][0].p2_distance = 500;*/

	print_board_old(f.x_max, f.y_max, board);
	i = 0;
	while (i++ < 5500)
	  {
		boundary_draw_new(board, &f);
		print_board_old(f.x_max, f.y_max, board);
		//board_print(board, f);
		getchar();
		if (i % 2)
		{
			//pc = get_piece(pc);
			best_position = get_best_position(board, &board_cpy, pc, &f);
			//printf("best_position - x: %d, y: %d\n", best_position.x, best_position.y);
			piece_write(&board, pc, best_position);
		}
		else
		{
			best_position = get_best_position_for_p2(board, &board_cpy, pc, &f);
			piece_write_for_p2(&board, pc, best_position);
		}
		//printf("score = %.2f / %d\n", board_score_calc(board, f), f.x_max * f.y_max); fflush(stdout);
	}
	return (0);
}
