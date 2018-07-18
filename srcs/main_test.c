/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/18 02:14:50 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	**get_piece(int		**piece)
{
	char	*buf;
	int		y_size;
	int		i;
	int		j;

	y_size = 0;
	i = 0;
	get_next_line(0, &buf);
	y_size = ft_atoi(&buf[5]);
	if (!(piece = malloc(sizeof(int *) * y_size + 1)))
		return (0);
	piece[y_size] = NULL;
	while (i < y_size)
	{
		get_next_line(0, &buf);
		if (!(piece[i] = malloc(sizeof(int) * ft_strlen(buf) + 1)))
			return (NULL);
		j = -1;
		while (buf[++j])
			piece[i][j] = (buf[j] == '*');
		piece[i][j] = -1;
		i++;
	}
	return (piece);
}

void	print_piece(int **piece)
{
	int i;
	int j;
	
	int fd = open("./coucou", O_RDWR | O_CREAT | O_APPEND);
	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j] != -1)
		{
			ft_putnbr_fd(piece[i][j], fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
}

void	put_piece(t_sqrt **board, int **piece, t_filler game_settings)
{
	(void)board;
	(void)piece;
	(void)game_settings;
}

int	main(void)
{
	t_sqrt		**board;
	int			**piece;
	t_filler	game_settings;

	board = NULL;
	piece = NULL;
	game_settings = get_game_settings();
	if (!(board = board_malloc(game_settings)))
		return (1);

//	if (game_settings.opponent == 'X')
		//printf("debug"); fflush(stdout);
	while (42)
	{
		board = board_init(board, game_settings);
		piece = get_piece(piece);
		print_piece(piece);
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
