/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/25 17:16:03 by jboursal         ###   ########.fr       */
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
			if (possession == P2)
				ft_printf("[[red]]  X  [[end]]");
			else if (possession == P1)
				ft_printf("[[blue]]  O  [[end]]");
			else if (possession < 0.5 && possession > 0)
			{
				printf("\033[35m%03.f%% \033[0m", possession * 100); fflush(stdout);
			}
			else if (possession > 0.5 && possession < 1)
			{
				printf("\033[36m%03.f%% \033[0m", possession * 100); fflush(stdout);
			}
			else
			{
				printf("%03.f%% ", possession * 100); fflush(stdout);
			}
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
			if (possession == P1)
				printf("\033[31m  X  \033[0m");
			else if (possession == P2)
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
