/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/25 17:15:15 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	boundary_draw_old(t_sqrt **board, t_filler filler);
t_sqrt	**board_random(t_filler game_settings, int nb);
void	print_board_old(int x_max, int y_max, t_sqrt **board);
void	boundary_draw_new(t_sqrt **board, t_filler f);
void    board_cpy_reset(t_sqrt **board, t_sqrt ***board_cpy, t_filler game_settings);
int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs);
float   board_score_calc(t_sqrt **board, t_filler gs);

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
	char		pc_layout[3][3] = 
	{
		{'.','*','*'},
		{'.','.','*'},
		{'.','.','*'}
	};

	pc.layout = layout_init(pc_layout);
	pc.x_max = 3;
	pc.y_max = 3;
	pc.free_columns = 0;
	pc.free_lines = 0;
	point.x = 2;
	point.y = 6;

	f.x_max = 10;
	f.y_max = 10;
	board = board_random(f, 2);
	//board_cpy = board_random(f, 0);

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

	/*board[7][0].possession = P1;
	board[7][1].possession = P1;
	board[6][3].possession = P2;
	board[7][2].possession = P1;
	board[8][2].possession = P1;
	board[9][2].possession = P1;

	board[0][5].possession = P2;*/
	print_board_old(f.x_max, f.y_max, board);
	i = 0;
	//while (i++ < 500)
		boundary_draw_new(board, f);
	print_board_old(f.x_max, f.y_max, board);
	printf("score = %f\n", board_score_calc(board, f)); fflush(stdout);
/*
	score = calc_score(board, f);
	if (score > 0)
		printf("possession totale: \033[32m%.2f\033[37m\n", score);
	else
		printf("possession totale: \033[31m%.2f\033[37m\n", score);*/
	return (0);
}
