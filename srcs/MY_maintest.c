/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/18 02:44:45 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void		boundary_draw_old(t_sqrt **board, t_filler filler);
t_sqrt	**board_random(t_filler game_settings);
void	print_board_old(int x_max, int y_max, t_sqrt **board);

int	main(void)
{
	t_sqrt		**board;
	t_filler	f;
	int			i;
	float		score;

	f.x_max = 100;
	f.y_max = 100;
	board = board_random(f);

	//board[1][1].possession = FDF_P1;
	//board[1][2].possession = 0;
	//board[1][3].possession = 0;
	//board[0][3].possession = 0;
	//board[0][4].possession = 0;
	//board[f.y_max - 2][f.x_max - 2].possession = FDF_P2;
	//board[f.y_max - 3][f.x_max - 3].possession = 1;
	//board[f.y_max - 4][f.x_max - 4].possession = 1;
	//board[f.y_max - 5][f.x_max - 5].possession = 1;
	//board[f.y_max - 6][f.x_max - 6].possession = 1;

	print_board(f.x_max, f.y_max, board);
	i = 0;
	while (i++ < 500)
		boundary_draw_old(board, f);
	print_board_old(f.x_max, f.y_max, board);

	score = calc_score(board, f);
	if (score > 0)
		printf("possession totale: \033[32m%.2f\033[37m\n", score);
	else
		printf("possession totale: \033[31m%.2f\033[37m\n", score);
	return (0);
}