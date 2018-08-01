#include "../includes/filler.h"

void    board_print(t_sqrt **board, t_filler gs)
{
	printf("BOARD_PRINT\n"); fflush(stdout);
	int x;
	int y;
	float possession;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			//	printf("%3.f ", board[y][x].p2_distance);
			possession = board[y][x].possession;
			if (possession == P1)
				printf("  O  ");
			else if (possession == P2)
				printf("  X  ");
			else
				printf("%3.f%% ", possession * 100);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
