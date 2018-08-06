/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/05 23:09:45 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_sqrt		tile_init(t_filler game_settings, char position)
{
	t_sqrt tile;

	tile.p1_distance = game_settings.x_max * game_settings.y_max;
	tile.p2_distance = game_settings.x_max * game_settings.y_max;
	if (((position == 'O' || position == 'o') && game_settings.opponent == P1)
		|| (position == 'X' | position == 'x'
		&& game_settings.opponent == P2))
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

t_sqrt		**board_init(t_sqrt **board, t_filler game_settings)
{
	char	buf[BUFF_GNL];
	int		x;
	int		y;

	y = 0;
	while (y < game_settings.y_max)
	{
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

t_filler	get_game_settings(void)
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
