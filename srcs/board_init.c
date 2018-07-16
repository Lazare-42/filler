/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/16 19:03:15 by jboursal         ###   ########.fr       */
=======
/*   Updated: 2018/07/16 19:07:14 by lazrossi         ###   ########.fr       */
>>>>>>> 954600c24ef5c421fa2fcd343b68037c68fc5b8f
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_sqrt	**board_init(int x_max, int y_max)
{
	int		y;
	int		x;
	t_sqrt	**board;

	board = NULL;
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
			board[y][x].possession = 0.5;
			x++;
		}
		y++;
	}
	return (board);
}

t_sqrt	**return_board(void)
{
	t_sqrt	**board;

	board = NULL;
	if (!(board = board_init
}
