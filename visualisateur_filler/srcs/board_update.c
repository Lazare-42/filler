/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:02:11 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/04 13:02:47 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	board_update(t_sqrt **board, t_filler *gs)
{
	board_distance_reset(board, *gs);
	board_distance_update_1(board, *gs);
	board_distance_update_2(board, *gs);
	board_distance_update_3(board, *gs);
	board_distance_update_4(board, *gs);
	board_distance_update_5(board, *gs);
	board_distance_update_6(board, *gs);
	board_distance_update_7(board, *gs);
	board_distance_update_8(board, *gs);
	board_possession_update(board, *gs);
	get_total_possession(board, gs);
}
