/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/18 02:20:43 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

t_sqrt	**board_random(t_filler game_settings)
{
	int		y;
	int		x;
	t_sqrt	**board;

	srand(time(0));
	board = NULL;
	if (!(board = (t_sqrt **)malloc(sizeof(t_sqrt *) * game_settings.y_max)))
		return (0);
	y = 0;
	while (y < game_settings.y_max)
	{
		if (!(board[y] = (t_sqrt *)malloc(sizeof(t_sqrt) * game_settings.x_max)))
			return (0);
		x = 0;
		while (x < game_settings.x_max)
		{
			board[y][x].boundary = 0;
			if (random()%100 < 3)
				board[y][x].possession = FDF_P1;
			else if (random()%100 > 97)
				board[y][x].possession = FDF_P2;
			else
				board[y][x].possession = 0;
			x++;
		}
		y++;
	}
	return (board);
}

t_sqrt	**board_malloc(t_filler game_settings)
{
	int		y;
	int		x;
	t_sqrt	**board;

	board = NULL;
	if (!(board = (t_sqrt **)malloc(sizeof(t_sqrt *) * game_settings.y_max)))
		return (0);
	y = 0;
	while (y < game_settings.y_max)
	{
		if (!(board[y] = (t_sqrt *)malloc(sizeof(t_sqrt) * game_settings.x_max)))
			return (0);
		x = 0;
		while (x < game_settings.x_max)
		{
			board[y][x].boundary = 0;
			board[y][x].possession = 0;
			x++;
		}
		y++;
	}
	return (board);
}

#include <fcntl.h>
#include <unistd.h>

t_sqrt **board_init(t_sqrt **board, t_filler game_settings)
{
	char	*buf;
	int		x;
	int		y;
	static int first = 0;

	y = 0;
	if (first)
		get_next_line(0, &buf);
	get_next_line(0, &buf);
	while (y < game_settings.y_max)
	{
		get_next_line(0, &buf);
		/*
		while (!ft_strstr(buf, "0"))
			get_next_line(0, &buf);
			*/
		x = 0;
		while (x < game_settings.x_max)
		{
			if (buf[x + 4] != '.' && board[y][x].possession > 0
			&& board[y][x].possession < 1)
				board[y][x].possession = (buf[x + 4] == game_settings.opponent
				|| buf[x + 4] == game_settings.opponent + 32);
			x++;
		}
		y++;
	}
	first = 1;
	return (board);
}

t_filler	get_game_settings()
{
	char		*buf;
	t_filler	game_settings;

	buf = NULL;
	get_next_line(0, &buf);
	if (ft_strstr(buf, "p2"))
		game_settings.opponent = 'O';
	else
		game_settings.opponent = 'X';
	while (!(ft_strstr(buf, "Plateau")))
		get_next_line(0, &buf);
	while (*buf && !(ft_isdigit(*buf)))
		buf++;
	game_settings.y_max = ft_atoi(buf);
	while (*buf && (ft_isdigit(*buf)))
		buf++;
	game_settings.x_max = ft_atoi(buf);
	return (game_settings);
}
/*
t_filler	update_map(t_sqrt **board, t_filler game_settings)
{
	char	*buf;
	int		x;
	int		y;

	y = 0;
}
*/
/*int main()
{
	if (!(board = board_malloc(game_settings)))
		return (0);
	board = board_init(board, game_settings);
	if (game_settings.opponent == 'O')
		// board_update
		// boundary_update
	while (42)
	{
		board = board_init(board, game_settings);
		// read new key
		// algorithm
		// output new_location
		//
		// board_update
		// boundary_update
	}
	return (0);
}
*/
