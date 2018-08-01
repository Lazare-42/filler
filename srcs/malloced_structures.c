/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloced_structures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:32:54 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/26 03:54:50 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
			board[y][x].possession = 0.5;
			board[y][x].p1_distance = game_settings.y_max * game_settings.x_max;
			board[y][x].p2_distance = game_settings.y_max  *game_settings.x_max;
			x++;
		}
		y++;
	}
	return (board);
}

void	get_piece(t_piece *piece)
{
	char	buf[4096];
	int		x;
	int		y;

	int		ret;

	y = -1;
	while (!ft_strstr(buf, "Piece"))
	{
		ret = fast_gnl(0, &buf);
		ft_printf("[[~/Documents/42/filler/test.txt]] '%s'", buf);
	}
	piece->y_max = ft_atoi(&buf[5]);
	ret = fast_gnl(0, &buf);
	ft_printf("[[~/Documents/42/filler/test.txt]] '%s'", buf);
	piece->x_max = ft_strlen(buf);
	if (piece->layout)
		ft_tabdel((void***)&piece->layout);
	if (!(piece->layout = (int**)malloc(sizeof(int *) * (piece->y_max + 1))))
		return ;
	piece->layout[piece->y_max] = NULL;
	while (++y < piece->y_max)
	{
		if (!(piece->layout[y] = (int *)malloc(sizeof(int) * (piece->x_max + 1))))
			return ;
		x = -1;
		while (++x < piece->x_max)
			piece->layout[y][x] = (buf[x] == '*');
		if (y < piece->y_max - 1)
		{
			ret = fast_gnl(0, &buf);
			ft_printf("[[~/Documents/42/filler/test.txt]] '%s'", buf);
		}
	}
}
