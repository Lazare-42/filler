#include "../includes/filler.h"

void    board_distance_update_5(t_sqrt **board, t_filler gs)
{
	int     x;
	int     y;
	int     p1_d_tmp;
	int     p2_d_tmp;
	float   possession;

	y = 1;
	while (y < gs.y_max)
	{
		x = 1;
		while (x < gs.x_max)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y - 1][x - 1].p1_distance + 2;
			p2_d_tmp = board[y - 1][x - 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x++;
		}
		y++;
	}
}

void    board_distance_update_6(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float   possession;

	x = gs.x_max - 2;
	while (x >= 0)
	{
		y = 1;
		while (y < gs.y_max)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y - 1][x + 1].p1_distance + 2;
			p2_d_tmp = board[y - 1][x + 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y++;
		}
		x--;
	}
}

void    board_distance_update_7(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float   possession;

	y = gs.y_max - 2;
	while (y >= 0)
	{
		x = gs.x_max - 2;
		while (x >= 0)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y + 1][x + 1].p1_distance + 2;
			p2_d_tmp = board[y + 1][x + 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x--;
		}
		y--;
	}
}

void    board_distance_update_8(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float   possession;

	x = 1;
	while (x < gs.x_max)
	{
		y = gs.y_max - 2;
		while (y >= 0)
		{
			possession = board[y][x].possession;
			p1_d_tmp = board[y + 1][x - 1].p1_distance + 2;
			p2_d_tmp = board[y + 1][x - 1].p2_distance + 2;
			if (p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y--;
		}
		x++;
	}
}
