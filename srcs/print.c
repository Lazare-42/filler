/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/17 02:15:12 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*debug*/
#include "../includes/filler.h"

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
			if (possession == 0)
				printf("\033[31m X  \033[0m");
			else if (possession == 1)
				printf("\033[34m O  \033[0m");
			else if (possession < 0.5 && possession > 0)
				printf("\033[35m%02.f%% \033[0m", possession * 100);
			else if (possession > 0.5 && possession < 1)
				printf("\033[36m%02.f%% \033[0m", possession * 100);
			else
				printf("%02.f%% ", possession * 100);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
