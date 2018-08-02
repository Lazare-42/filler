/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 09:03:11 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

t_sqrt tile_init(char position)
{
	t_sqrt tile;

	tile.p1_distance = 100000;
	tile.p2_distance = 100000;
	if (position == 'O' || position == 'o')
	{
		tile.possession = P1;
		tile.p1_distance = 0;
	}
	else if (position == 'X' || position == 'x')
	{
		tile.possession = P2;
		tile.p2_distance = 0;
	}
	return (tile);
}

t_sqrt **board_init(t_sqrt **board, t_filler *game_settings)
{
	char	*buf;
	int		x;
	int		y;

	y = 0;
	while (y < game_settings->y_max)
	{
		x = 0;
		get_next_line(0, &buf);
		if (ft_strstr(buf, "fin"))
		{
			find_winner(game_settings, buf);
			return (board);
		}
		while (x < game_settings->x_max)
		{
			if (buf[x + 4] != '.' && board[y][x].possession != -1)
				board[y][x] = tile_init(buf[x + 4]);
			x++;
		}
		y++;
	}
	return (board);
}

void	put_sentence(t_filler * gs, int player)
{
	if (player == P1)
	{
		ft_memset(gs->p1_info, 0, 1024);
		ft_memcpy(gs->p1_info, "Possession estimation for P1, ",
		ft_strlen("Possession estimation for P1, "));
	}
	else if (player == P2)
	{
		ft_memset(gs->p2_info, 0, 1024);
		ft_memcpy(gs->p2_info, "Possession estimation for P2, ",
		ft_strlen("Possession estimation for P2, "));
	}
}


void	set_player_info(char *buf, t_filler *gs, int player)
{
	char	*tmp;
	char	name[1024];

	tmp = NULL;
	put_sentence(gs, player);
	if (ft_strstr(buf, "players"))
		buf = ft_strstr(buf, "players");
	buf = ft_strstr(buf, "/");
	buf += 1;
	if (ft_strstr(buf, "."))
		tmp = ft_strstr(buf, ".");
	ft_memset(name, 0, 1024);
	if (tmp)
		ft_memcpy(name, buf, ft_strlen(buf) - ft_strlen(tmp));
	else
		ft_memcpy(name, buf, ft_strlen(buf) - 1);
	if (player == P1)
		ft_memcpy(gs->p1_info + ft_strlen(gs->p1_info), name, ft_strlen(name));
	else if (player == P2)
		ft_memcpy(gs->p2_info + ft_strlen(gs->p2_info), name, ft_strlen(name));
}

t_filler	get_game_settings()
{
	char			*buf;
	static t_filler	game_settings;
	static int 		first = 1;
	int				i;

	get_next_line(0, &buf);
	i = 0;
	game_settings.game_over = 0;
	while (!(ft_strstr(buf, "Plateau")))
	{
		get_next_line(0, &buf);
		if (ft_strstr(buf, "exec p1"))
			set_player_info(buf, &game_settings, P1);
		if (ft_strstr(buf, "exec p2"))
			set_player_info(buf, &game_settings, P2);
	}
	while (buf[i] && !(ft_isdigit(buf[i])))
		i++;
	game_settings.y_max = ft_atoi(&buf[i]);
	while (buf[i] && (ft_isdigit(buf[i])))
		i++;
	game_settings.x_max = ft_atoi(&buf[i]);
	first = 0;
	return (game_settings);
}
