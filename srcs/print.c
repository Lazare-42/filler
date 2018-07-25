/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/25 23:11:12 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*debug*/
#include "../includes/filler.h"

void	print_board_old(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (board[y][x].possession == P1)
				ft_printf("[[~/Documents/42/filler/test_map.txt]][[swapp]][[red]] ");
			else if (board[y][x].possession == P2)
				ft_printf("[[~/Documents/42/filler/test_map.txt]][[end]][[swapp]][[blue]] ");
			else
				ft_printf("[[~/Documents/42/filler/test_map.txt]][[end]] ");
			x++;
		}
		ft_printf("[[~/Documents/42/filler/test_map.txt]]\n");
		y++;
	}
	ft_printf("[[~/Documents/42/filler/test_map.txt]]\n");
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
