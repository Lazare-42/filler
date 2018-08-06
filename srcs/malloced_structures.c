/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloced_structures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:32:54 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/05 23:53:43 by lazrossi         ###   ########.fr       */
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
		if (!(board[y] = (t_sqrt *)malloc(sizeof(t_sqrt)
			* game_settings.x_max)))
			return (0);
		x = 0;
		while (x < game_settings.x_max)
		{
			board[y][x].possession = 0.5;
			board[y][x].p1_distance = game_settings.y_max * game_settings.x_max;
			board[y][x].p2_distance = game_settings.y_max * game_settings.x_max;
			x++;
		}
		y++;
	}
	return (board);
}

void	get_piece(t_piece *pc)
{
	char	buf[4096];
	int		x;
	int		y;

	y = -1;
	while (!ft_strstr(buf, "Piece"))
		fast_gnl(0, &buf);
	pc->y_max = ft_atoi(&buf[5]);
	fast_gnl(0, &buf);
	pc->x_max = ft_strlen(buf);
	if (pc->layout)
		ft_tabdel((void***)&pc->layout);
	if (!(pc->layout = (int**)malloc(sizeof(int *) * (pc->y_max + 1))))
		return ;
	pc->layout[pc->y_max] = NULL;
	while (++y < pc->y_max)
	{
		if (!(pc->layout[y] = (int *)malloc(sizeof(int) * (pc->x_max + 1))))
			return ;
		x = -1;
		while (++x < pc->x_max)
			pc->layout[y][x] = (buf[x] == '*');
		if (y < pc->y_max - 1)
			fast_gnl(0, &buf);
	}
}
