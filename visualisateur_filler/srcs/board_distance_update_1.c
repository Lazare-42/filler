/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_distance_update_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:50:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/04 12:55:07 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	board_distance_update_1(t_sqrt **board, t_filler gs)
{
	int		x;
	int		y;
	int		p1_d_tmp;
	int		p2_d_tmp;
	float	possession;

	y = 0;
	while (y < gs.y_max)
	{
		x = 1;
		while (x < gs.x_max)
		{
			p1_d_tmp = board[y][x - 1].p1_distance + 1;
			p2_d_tmp = board[y][x - 1].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x++;
		}
		y++;
	}
}

void	board_distance_update_2(t_sqrt **board, t_filler gs)
{
	int		x;
	int		y;
	int		p1_d_tmp;
	int		p2_d_tmp;
	float	possession;

	x = gs.x_max - 1;
	while (x >= 0)
	{
		y = 1;
		while (y < gs.y_max)
		{
			p1_d_tmp = board[y - 1][x].p1_distance + 1;
			p2_d_tmp = board[y - 1][x].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y++;
		}
		x--;
	}
}

void	board_distance_update_3(t_sqrt **board, t_filler gs)
{
	int		x;
	int		y;
	int		p1_d_tmp;
	int		p2_d_tmp;
	float	possession;

	y = gs.y_max - 1 + 1;
	while (--y >= 0)
	{
		x = gs.x_max - 2 + 1;
		while (--x >= 0)
		{
			p1_d_tmp = board[y][x + 1].p1_distance + 1;
			p2_d_tmp = board[y][x + 1].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
			{
				board[y][x].p1_distance = p1_d_tmp;
			}
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
			{
				board[y][x].p2_distance = p2_d_tmp;
			}
		}
	}
}

void	board_distance_update_4(t_sqrt **board, t_filler gs)
{
	int		x;
	int		y;
	int		p1_d_tmp;
	int		p2_d_tmp;
	float	possession;

	x = 0;
	while (x < gs.x_max)
	{
		y = gs.y_max - 2;
		while (y >= 0)
		{
			p1_d_tmp = board[y + 1][x].p1_distance + 1;
			p2_d_tmp = board[y + 1][x].p2_distance + 1;
			possession = board[y][x].possession;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y--;
		}
		x++;
	}
}
