/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/16 18:45:01 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_sqrt	**board_init(int x_max, int y_max, t_sqrt ***b)
{
	int		y;
	int		x;
	t_sqrt	**board;

	board = *b;
	if (!(board = (t_sqrt **)malloc(sizeof(t_sqrt *) * y_max)))
		return (0);
	y = 0;
	while (y < y_max)
	{
		if (!(board[y] = (t_sqrt *)malloc(sizeof(t_sqrt) * x_max)))
			return (0);
		x = 0;
		while (x < x_max)
		{
			board[y][x].boundary = 0;
			board[y][x].possession = 0;
			x++;
		}
		y++;
	}
	return (board);
}
