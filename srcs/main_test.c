/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:02:34 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 19:24:54 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/19 15:57:46 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		try_insert(t_piece piece, t_sqrt **board_tmp, char **location, int x, int y)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	tmp = NULL;
	while (i < piece.free_lines)
	{
		j = 0;
		while (j < piece.free_columns)
		{
			if (piece.piece_layout[i][i] && board_tmp[x + i][y + j].possession == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (!(tmp = ft_itoa(x - piece.free_columns)))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	if (!(tmp = ft_strdup(" ")))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	if (!(tmp = ft_itoa(y - piece.free_lines)))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	if (!(tmp = ft_strdup("\n")))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	return (1);
}

void	put_piece(t_sqrt **board,t_piece piece, t_filler game_settings)
{
	int x;
	int y;
	char *location;
	t_sqrt **board_tmp;

	x = 0;
	location = NULL;
	(void)board;
	if (!(board_tmp = board_malloc(game_settings)))
		return ;
	while (x < game_settings.y_max - piece.free_lines)
	{
		y = 0;
		while (y < game_settings.x_max - piece.free_columns)
		{
			board_tmp = board_init(board_tmp, game_settings);
			if (board_tmp[x][y].possession == 0)
			{
				if (try_insert(piece, board_tmp, &location, x, y))
				{
					ft_putstr(location);
					return ;
				}
			}
			y++;
		}
		x++;
	}
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
		board = board_init(board, game_settings);
		//print_board(game_settings.x_max, game_settings.y_max, board);
//		piece = get_piece(piece);
//		print_piece(piece);
//		put_piece(board, piece, game_settings);
//		printf("%d %d\n", 3, 3); fflush(stdout);
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
