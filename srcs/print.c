/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/17 20:16:29 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*debug*/
#include "../includes/filler.h"
#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <unistd.h>

void	print_board(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;

	int fd = open("./coucou", O_RDWR | O_CREAT | O_APPEND);
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			ft_putnbr_fd(board[y][x].possession, fd);
			x++;
		}
		ft_putstr_fd("\n", fd);
		y++;
	}
	ft_putstr_fd("\n", fd);
	close(fd);
}
