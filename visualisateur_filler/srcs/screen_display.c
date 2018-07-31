#include "../includes/filler.h"
#include "../minilibx_macos/mlx.h"

void	screen_fill(int **screen, int player, int where_to, t_filler game_settings)
{
	int x;
	int y;
	int space;

	y = 0;
	while (y < (Y_SIZE - BOARD) / game_settings.y_max - 1)
	{
		x = 0;
		while (x  < X_SIZE / game_settings.x_max - 1)
		{
			if (player == P1)
				(*screen)[where_to + x] = 0x9370DB; 
			else if (player == P2)
				(*screen)[where_to + x] = 0x37FDFC;
			else
				(*screen)[where_to + x] = 0xA9A9A9;
			x++;
		}
		space = -1;
		where_to += X_SIZE;
		y++;
	}
}

void	display_pieces(t_filler game_settings, t_sqrt **board, int **screen)
{
	int		y;
	int		x;
	int		where_to;
	int 	tmp;

	y = -1;
	where_to = (X_SIZE % game_settings.x_max) / 2 + BOARD * X_SIZE;
	where_to += (Y_SIZE - BOARD) % game_settings.y_max * X_SIZE;
	while (++y < game_settings.y_max)
	{
		x = -1;
		tmp = where_to;
		while (++x < game_settings.x_max)
		{
			if (board[y][x].possession == P1)
				screen_fill(screen, P1, tmp, game_settings);
			else if (board[y][x].possession == P2)
				screen_fill(screen, P2, tmp, game_settings);
			else
				screen_fill(screen, BOARD, tmp, game_settings);
			tmp += X_SIZE / game_settings.x_max;
		}
		where_to += (Y_SIZE - BOARD) / game_settings.y_max * X_SIZE;
	}
}

void	add_percentage(t_mlx mlx, t_filler game_settings, int x, int y, int player)
{
	char		percent[6];
	int			convert;

	percent[5] = 0;
	if (player == P1)
		convert = game_settings.p1_possession;
	else
		convert = game_settings.p2_possession;
	percent[4] = '%';
	percent[3] = convert % 10 + '0';
	convert /= 10;
	percent[2] = '.';
	percent[1] = convert % 10 + '0';
	convert /= 10;
	percent[0] = convert % 10 + '0';
	if (player == P1)
		mlx_string_put(mlx.mlx, mlx.win, x, y, 0x9370DB, percent);
	else
		mlx_string_put(mlx.mlx, mlx.win, x, y, 0x37FDFC, percent);
}

void	put_player_info(t_mlx mlx, t_filler gs, int player)
{
	if (player == P1)
		mlx_string_put(mlx.mlx, mlx.win, (X_SIZE - (ft_strlen(gs.p1_info)) * 10) / 2, 0, 0xA9A9A9, gs.p1_info);
	else
		mlx_string_put(mlx.mlx, mlx.win, (X_SIZE - (ft_strlen(gs.p2_info)) * 10) / 2, 17, 0xA9A9A9, gs.p2_info);
	if (player == 1)
		add_percentage(mlx, gs, (X_SIZE + (ft_strlen(gs.p1_info) + 4) * 10) / 2, 0, player);
	else
		add_percentage(mlx, gs, (X_SIZE + (ft_strlen(gs.p2_info) + 4) * 10) / 2, 17, player);
}
