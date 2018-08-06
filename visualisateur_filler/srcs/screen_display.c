/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:11:49 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 17:31:45 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../minilibx_macos/mlx.h"

void	screen_fill(int **screen, int player, int where_to, t_filler gs)
{
	int x;
	int y;

	y = -1;
	while (++y < (Y_SIZE - BOARD) / gs.y_max - 1)
	{
		x = -1;
		while (++x < X_SIZE / gs.x_max - 1)
		{
			if (player == P1)
				(*screen)[where_to + x] = VIOLET;
			else if (player == P2)
				(*screen)[where_to + x] = CYAN;
		}
		where_to += X_SIZE;
	}
}

void	screen_fill_possession(int **screen, t_sqrt tile, int where_to,
		t_filler gs)
{
	int					x;
	int					y;
	float				possession;
	t_color_compound	violet;
	t_color_compound	cyan;

	y = -1;
	possession = (float)(tile.p2_distance /
			(tile.p2_distance + tile.p1_distance));
	if (possession > (float)0.5)
	{
		possession -= (float)0.5;
		violet = ft_decompose_color(VIOLET);
		violet.red = (int)(((float)violet.red * possession) / (float)1.3);
		violet.green = (int)(((float)violet.green * possession) / (float)1.3);
		violet.blue = (int)(((float)violet.blue * possession) / (float)1.3);
		violet.rgb = violet.red << 16 | violet.green << 8 | violet.blue;
		while (++y < (Y_SIZE - BOARD) / gs.y_max - 1)
		{
			x = -1;
			while (++x < X_SIZE / gs.x_max - 1)
				(*screen)[where_to + x] = violet.rgb;
			where_to += X_SIZE;
		}
	}
	else
	{
		possession += (float)0.5;
		cyan = ft_decompose_color(CYAN);
		cyan.red = (int)((float)cyan.red * (1 - possession)) / 2;
		cyan.green = (int)((float)cyan.green * (1 - possession)) / 2;
		cyan.blue = (int)((float)cyan.blue * (1  - possession)) / 2;
		cyan.rgb = cyan.red << 16 | cyan.green << 8 | cyan.blue;
		while (++y < (Y_SIZE - BOARD) / gs.y_max - 1)
		{
			x = -1;
			while (++x < X_SIZE / gs.x_max - 1)
				(*screen)[where_to + x] = cyan.rgb;
			where_to += X_SIZE;
		}
	}
}

void	display_pieces(t_filler gs, t_sqrt **board, int **screen)
{
	int		y;
	int		x;
	int		where_to;
	int		tmp;
	int		square_size;

	y = -1;
	where_to = (X_SIZE % gs.x_max) / 2 + BOARD * X_SIZE;
	where_to += (Y_SIZE - BOARD) % gs.y_max * X_SIZE;
	square_size = (Y_SIZE - BOARD) / gs.y_max * X_SIZE;
	while (++y < gs.y_max)
	{
		x = -1;
		tmp = where_to;
		while (++x < gs.x_max)
		{
			if (board[y][x].possession != P2 && board[y][x].possession != P1)
				screen_fill_possession(screen, board[y][x], tmp, gs);
			else
				screen_fill(screen, board[y][x].possession, tmp, gs);
			tmp += X_SIZE / gs.x_max;
		}
		where_to += square_size;
	}
}

void	add_percentage(t_mlx mlx, t_filler gs, int x, int y)
{
	char		percent[6];
	int			convert;

	percent[5] = 0;
	if (gs.player == P1)
		convert = gs.p1_possession;
	else
		convert = gs.p2_possession;
	percent[4] = '%';
	percent[3] = convert % 10 + '0';
	convert /= 10;
	percent[2] = '.';
	percent[1] = convert % 10 + '0';
	convert /= 10;
	percent[0] = convert % 10 + '0';
	if (gs.player == P1)
		mlx_string_put(mlx.mlx, mlx.win, x, y, VIOLET, percent);
	else
		mlx_string_put(mlx.mlx, mlx.win, x, y, CYAN, percent);
}

void	put_player_info(t_mlx mlx, t_filler gs, int player)
{
	if (player == P1)
		mlx_string_put(mlx.mlx, mlx.win,
				(X_SIZE - (ft_strlen(gs.p1_info)) * 10) / 2,
				0, GREY, gs.p1_info);
	else
		mlx_string_put(mlx.mlx, mlx.win,
				(X_SIZE - (ft_strlen(gs.p2_info)) * 10) / 2,
				17, GREY, gs.p2_info);
	if (player == P1)
	{
		gs.player = P1;
		add_percentage(mlx, gs,
				(X_SIZE + (ft_strlen(gs.p1_info) + 4) * 10) / 2, 0);
	}
	else
	{
		gs.player = P2;
		add_percentage(mlx, gs,
				(X_SIZE + (ft_strlen(gs.p2_info) + 4) * 10) / 2, 17);
	}
}
