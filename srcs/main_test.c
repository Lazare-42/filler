/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/16 21:39:54 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_sqrt	**board;
	int		x_max;
	int		y_max;

	x_max = 10;
	y_max = 10;
	board = board_init(x_max, y_max);
	print_board(x_max, y_max, board);
	return (0);
}
