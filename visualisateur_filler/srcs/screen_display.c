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
struct s_color_compound {
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
};

struct s_color_compound	decompose_color(int color)
{
	struct s_color_compound c;
	c.red = (char)(color >> 16);
	c.green = (char)((color & 0x00ff00) >> 8);
	c.blue = (char)(color & 0x0000ff);
	return c;
}

void	screen_fill_possession(int **screen, t_sqrt tile, int where_to, t_filler game_settings)
{
	int x;
	int y;
	int space;
	float possession;
	int red;
	int green;
	int blue;
	struct s_color_compound violet = decompose_color(0x9370DB);

	int color;
	y = 0;
	possession = (float)(tile.p2_distance / (tile.p2_distance + tile.p1_distance));
	while (y < (Y_SIZE - BOARD) / game_settings.y_max - 1)
	{
		x = 0;
		while (x  < X_SIZE / game_settings.x_max - 1)
		{
			red = (int)((float)violet.red * possession) / 2;
			green = (int)((float)violet.green * possession) / 2;
			blue = (int)((float)violet.blue * possession) / 2;
			color = red << 16 | green << 8 | blue;
			(*screen)[where_to + x] = color; 
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
				screen_fill_possession(screen, board[y][x], tmp, game_settings);
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
