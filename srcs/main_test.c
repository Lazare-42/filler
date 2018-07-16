/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/17 01:33:28 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int	main(void)
{
	t_sqrt		**board;
	t_filler	f;
	int			i;
	float		score;

	f.x_max = 20;
	f.y_max = 20;
	board = board_malloc(f);

	board[1][1].possession = 0;
	board[1][2].possession = 0;
	board[1][3].possession = 0;
	board[0][3].possession = 0;
	board[0][4].possession = 0;
	board[f.y_max - 2][f.x_max - 2].possession = 1;
	board[f.y_max - 3][f.x_max - 2].possession = 1;
	board[f.y_max - 4][f.x_max - 2].possession = 1;
	board[f.y_max - 4][f.x_max - 3].possession = 1;
	board[f.y_max - 5][f.x_max - 4].possession = 1;

	i = 0;
	while (i++ < 133)
		boundary_draw(board, f);
	print_board(f.x_max, f.y_max, board);

	score = calc_score(board, f);
	if (score > f.x_max * f.y_max)
		printf("possession totale: \033[31m%.2f / %d\033[0m\n", score, f.x_max * f.y_max);
	else
		printf("possession totale: \033[32m%.2f / %d\033[0m\n", score, f.x_max * f.y_max);


	return (0);
}
