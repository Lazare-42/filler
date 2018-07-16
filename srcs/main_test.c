/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/17 00:25:40 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_sqrt		**board;
	t_filler	f;

	f.x_max = 10;
	f.y_max = 15;
	board = board_malloc(f);
	board[2][2].possession = 0;
	board[f.y_max - 2][f.x_max - 2].possession = 1;
	boundary_draw(board, f);
	print_board(f.x_max, f.y_max, board);

	return (0);
}
