#include "../includes/filler.h"

void	board_possession_update(t_sqrt **board, t_filler filler)
{
	int			x;
	int			y;
	float		p2_d;
	float		possession;

	y = 0;
	while (y < filler.y_max)
	{
		x = 0;
		while (x < filler.x_max)
		{
			p2_d = board[y][x].p2_distance;
			possession = board[y][x].possession;
			board[y][x].possession = p2_d / (p2_d + board[y][x].p1_distance);
			x++;
		}
		y++;
	}
}

void	get_total_possession(t_sqrt **board, t_filler *gs)
{
	int x;
	int y;
	float total_possession;
	float total_size;

	y = 0;
	total_size = gs->x_max * gs->y_max;
	total_possession = 0;
	while (y < gs->y_max)
	{
		x = 0;
		while (x < gs->x_max)
		{
			total_possession += board[y][x].possession;
			x++;
		}
		y++;
	}
	gs->p1_possession = total_possession / total_size;
	gs->p2_possession = 1 - gs->p1_possession; 
	gs->p2_possession *= 1000;
	gs->p1_possession *= 1000;
}
