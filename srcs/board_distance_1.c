#include "../includes/filler.h"

void    board_distance_update_1(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	y = 0;
	while (y < gs.y_max)
	{
		x = 1;
		while (x < gs.x_max)
		{
			p1_d_tmp = board[y][x - 1].p1_distance + 1;
			p2_d_tmp = board[y][x - 1].p2_distance + 1;
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			possession = board[y][x].possession;
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x++;
		}
		y++;
	}
}

void    board_distance_update_2(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	x = gs.x_max - 1;
	while (x >= 0)
	{
		y = 1;
		while (y < gs.y_max)
		{
			p1_d_tmp = board[y - 1][x].p1_distance + 1;
			p2_d_tmp = board[y - 1][x].p2_distance + 1;
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			possession = board[y][x].possession;
			if (/*p1_d_tmp < PERIMETRE && */p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y++;
		}
		x--;
	}
}

void    board_distance_update_3(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	y = gs.y_max - 1;
	while (y >= 0)
	{
		x = gs.x_max - 2;
		while (x >= 0)
		{
			//printf("y: %d x: %d\n", y, x); fflush(stdout);
			p1_d_tmp = board[y][x + 1].p1_distance + 1;
			p2_d_tmp = board[y][x + 1].p2_distance + 1;
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			possession = board[y][x].possession;
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			x--;
		}
		y--;
	}
}

void    board_distance_update_4(t_sqrt **board, t_filler gs)
{
	int x;
	int y;
	int p1_d_tmp;
	int p2_d_tmp;
	float possession;

	x = 0;
	while (x < gs.x_max)
	{
		y = gs.y_max - 2;
		while (y >= 0)
		{
			p1_d_tmp = board[y + 1][x].p1_distance + 1;
			p2_d_tmp = board[y + 1][x].p2_distance + 1;
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			possession = board[y][x].possession;
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y--;
		}
		x++;
	}
}
