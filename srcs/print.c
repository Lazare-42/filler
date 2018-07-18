/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/18 19:20:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*debug*/
#include "../includes/filler.h"

void	print_board_old(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;
	float	possession;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			possession = board[y][x].possession;
			if (possession == FDF_P1)
				printf("\033[31m  X  \033[0m");
			else if (possession == FDF_P2)
				printf("\033[34m  O  \033[0m");
			else if (possession < 0.5 && possession > 0)
				printf("\033[35m%03.f%% \033[0m", possession * 100);
			else if (possession > 0.5 && possession < 1)
				printf("\033[36m%03.f%% \033[0m", possession * 100);
			else
				printf("%03.f%% ", possession * 100);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	print_board(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;
	float	possession;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			possession = board[y][x].possession;
			if (possession == FDF_P1)
				printf("\033[31m  X  \033[0m");
			else if (possession == FDF_P2)
				printf("\033[34m  O  \033[0m");
			else if (possession < 0)
				printf("\033[35m%+04.f \033[0m", possession);
			else if (possession > 0)
				printf("\033[36m%+04.f \033[0m", possession);
			else
				printf("%+04.f ", possession);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
