/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/05 05:57:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

t_sqrt	**board_random(t_filler game_settings, int nb)
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
			board[y][x].p1_distance = 1000;
			board[y][x].p2_distance = 1000;
			if (random()%100 < nb)
			{
				board[y][x].p1_distance = 0;
				board[y][x].possession = P1;
			}
			else if (random()%100 > 100 - nb)
			{
				board[y][x].p2_distance = 0;
				board[y][x].possession = P2;
			}
			else
				board[y][x].possession = 0.5;
			x++;
		}
		y++;
	}
	return (board);
}


#include <fcntl.h>
#include <unistd.h>

t_sqrt tile_init(t_filler game_settings, char position)
{
	t_sqrt tile;

	tile.p1_distance = game_settings.x_max * game_settings.y_max;
	tile.p2_distance = game_settings.x_max * game_settings.y_max;
	if (((position == 'O' || position == 'o') && game_settings.opponent == P1)
			|| (position == 'X' | position == 'x' && game_settings.opponent == P2))
	{
		tile.possession = P2;
		tile.p2_distance = 0;
	}
	else
	{
		tile.possession = P1;
		tile.p1_distance = 0;
	}
	return (tile);
}

t_sqrt **board_init(t_sqrt **board, t_filler game_settings)
{
	char	buf[BUFF_GNL];
	int		x;
	int		y;

	y = 0;
	while (y < game_settings.y_max)
	{
		ft_printf("[[~/Documents/42/filler/thread.txt]]%d\n", y);
		fast_gnl(0, &buf);
		x = 0;
		while (x < game_settings.x_max)
		{
			if (buf[x + 4] != '.' && board[y][x].possession > 0
							&& board[y][x].possession < 1)
				board[y][x] = tile_init(game_settings, buf[x + 4]);
			x++;
		}
		y++;
	}
	return (board);
}

t_filler	get_game_settings()
{
	char		buf[4096];
	t_filler	game_settings;
	int			i;

	i = 0;
	fast_gnl(0, &buf);
	if (ft_strstr(buf, "p1"))
		game_settings.opponent = P2;
	else
		game_settings.opponent = P1;
	fast_gnl(0, &buf);
	while (buf[i] && !(ft_isdigit(buf[i])))
		i++;
	game_settings.y_max = ft_atoi(&buf[i]);
	while (buf[i] && (ft_isdigit(buf[i])))
		i++;
	game_settings.x_max = ft_atoi(&buf[i]);
	game_settings.game_over = 0;
	return (game_settings);
}
