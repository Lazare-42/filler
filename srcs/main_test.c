/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/18 14:19:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	put_piece(t_sqrt **board, int **piece, t_filler game_settings)
{
	t_sqrt		**board_tmp;

	board_tmp = NULL;
	if (!(board_tmp = board_malloc(game_settings)))
		return ;
	board_tmp = board_init(board, game_settings);
	(void)board;
	(void)piece;
	(void)game_settings;
}

int	main(void)
{
	t_sqrt		**board;
	t_piece		piece;
	t_filler	game_settings;

	board = NULL;
	game_settings = get_game_settings();
	if (!(board = board_malloc(game_settings)))
		return (1);

//	if (game_settings.opponent == 'X')
		//printf("debug"); fflush(stdout);
	piece.piece_layout = NULL;
	while (42)
	{
		board = board_init(board, game_settings);
		piece = get_piece(piece);
		print_piece(piece.piece_layout);
	//	put_piece(piece, board);
		printf("%d %d\n", 3, 3); fflush(stdout);
		print_board(game_settings.x_max, game_settings.y_max, board);
	}
	//board[1][1].possession = 0;
	//board[1][2].possession = 0;
	//board[1][3].possession = 0;
	//board[0][3].possession = 0;
	//board[0][4].possession = 0;
	//board[f.y_max - 2][f.x_max - 2].possession = 1;
	//board[f.y_max - 3][f.x_max - 3].possession = 1;
	//board[f.y_max - 4][f.x_max - 4].possession = 1;
	//board[f.y_max - 5][f.x_max - 5].possession = 1;
	//board[f.y_max - 6][f.x_max - 6].possession = 1;

	return (0);
}
