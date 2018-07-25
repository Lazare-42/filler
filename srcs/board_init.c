/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/25 11:26:54 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

t_sqrt	**board_random(t_filler game_settings)
{
	int		y;
	int		x;
	t_sqrt	**board;

	srand(time(NULL));
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
			if (random()%100 < 2)
				board[y][x].possession = P1;
			else if (random()%100 > 98)
				board[y][x].possession = P2;
			else
				board[y][x].possession = 0;
			x++;
		}
		y++;
	}
	return (board);
}


#include <fcntl.h>
#include <unistd.h>

/*
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
		x = 0;
		while (x < game_settings.x_max)
		{
			if (buf[x + 4] != '.' && board[y][x].possession > 0
			&& board[y][x].possession < 1)
			{
				if (buf[x][y] = game_settings.opponent + 32)
					board[x][y] = P1;
				else if (buf[x][y] = game_settings.opponent)
					board[x][y] = P1_NEW;
				else if (buf[x][y] = game_settings.opponent)
					board[x][y] = P1_NEW;
			}
				board[x][y] = 
				board[y][x].possession = (buf[x + 4] == game_settings.opponent
				|| buf[x + 4] == game_settings.opponent + 32);
			x++;
		}
		y++;
	}
	first = 1;
	print_board_old(game_settings.x_max, game_settings.y_max, board);
	return (board);
}
*/

t_filler	get_game_settings()
{
	char		*buf;
	t_filler	game_settings;

	buf = NULL;
	get_next_line(0, &buf);
	if (ft_strstr(buf, "p1"))
		game_settings.opponent = P2;
	else
		game_settings.opponent = P1;
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
