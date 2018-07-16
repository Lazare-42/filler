/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/16 22:33:29 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_sqrt	**board;
	int		x_max;
	int		y_max;

	x_max = 10;
	y_max = 15;
	board = board_malloc(x_max, y_max);
	board[2][2].possession = 0;
	board[y_max - 2][x_max - 2].possession = 1;
	boundary_draw(&board, x_max, y_max);
	print_board(x_max, y_max, board);

	return (0);
}
