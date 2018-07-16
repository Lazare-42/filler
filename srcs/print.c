/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/16 19:08:56 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*debug*/
#include "../includes/filler.h"

void	print_board(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			printf("%-4.2f ", board[y][x].possession);
			x++;
		}
		y++;
	}
}
