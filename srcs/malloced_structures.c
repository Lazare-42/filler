/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloced_structures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:32:54 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/18 19:20:36 by lazrossi         ###   ########.fr       */
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
			board[y][x].boundary = 0;
			board[y][x].possession = 0;
			board[y][x].p1_distance = game_settings.y_max + game_settings.x_max;
			board[y][x].p2_distance = game_settings.y_max + game_settings.x_max;
			x++;
		}
		y++;
	}
	return (board);
}

t_piece	get_piece(t_piece piece)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	get_next_line(0, &buf);
	piece.y_max = ft_atoi(&buf[5]);
	get_next_line(0, &buf);
	piece.x_max = ft_strlen(buf);
	if (piece.piece_layout)
		ft_tabdel((void***)&piece.piece_layout);
	if (!(piece.piece_layout = malloc(sizeof(int *) * piece.y_max + 1)))
		return (piece);
	piece.piece_layout[piece.y_max] = NULL;
	while (i < piece.y_max)
	{
		if (!(piece.piece_layout[i] = malloc(sizeof(int) * ft_strlen(buf))))
			return (piece);
		j = -1;
		while (++j < piece.x_max)
			piece.piece_layout[i][j] = (buf[j] == '*');
		i++;
		get_next_line(0, &buf);
	}
	return ((norm_piece(piece)));
}
