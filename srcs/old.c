
#include "../includes/filler.h"

t_sqrt	**board_random(t_filler game_settings, int nb)
{
	int		y;
	int		x;
	t_sqrt	**board;

	srand(time(NULL));
	board = NULL;
	if (!(board = (t_sqrt **)malloc(sizeof(t_sqrt *) * game_settings.y_max)))
		return (0);
	y = 0;
	while (y < game_settings.y_max)
	{
		if (!(board[y] = (t_sqrt *)malloc(sizeof(t_sqrt) * game_settings.x_max)))
			return (0);
		x = 0;
		while (x < game_settings.x_max)
		{
			board[y][x].p1_distance = 1000;
			board[y][x].p2_distance = 1000;
			if (random()%100 < nb)
			{
				board[y][x].p1_distance = 0;
				board[y][x].possession = P1;
			}
			else if (random()%100 > 100 - nb)
			{
				board[y][x].p2_distance = 0;
				board[y][x].possession = P2;
			}
			else
				board[y][x].possession = 0.5;
			x++;
		}
		y++;
	}
	return (board);
}


