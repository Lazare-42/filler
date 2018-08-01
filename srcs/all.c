/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/01 16:43:13 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	boundary_draw_old(t_sqrt **board, t_filler filler);
t_sqrt	**board_random(t_filler game_settings, int nb);
void	print_board_old(int x_max, int y_max, t_sqrt **board);
void	boundary_draw_new(t_sqrt **board, t_filler *f);
void    board_cpy_reset(t_sqrt **board, t_sqrt ***board_cpy, t_filler game_settings);
int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs);
float   board_score_calc(t_sqrt **board, t_filler gs);
t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs);
t_point get_best_position_for_p2(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs);
void    board_print(t_sqrt **board, t_filler gs);
void    piece_write(t_sqrt ***board, t_piece pc, t_point o);
void    piece_write_for_p2(t_sqrt ***board, t_piece pc, t_point o);
/*
static void	mask_init(t_filler gs)
{
	int	y;
	int	x;

	float	model[7][7] = 
	{
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1}
	};
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 7)
		{
				gs.mask[y][x] = model[y][x];
			x++;
			printf("%.f ", model[y][x]);
			//printf("%.f ", gs.mask[y][x]);
		}
		printf("\n");
		y++;
	}
}*/

static float	**mask_init(void)
{
	int	y;
	int	x;
	float	**ret;
	float	model[7][7] = 
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,1,1,1,0,0},
		{0,0,1,1,1,0,0},
		{0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	};

	y = 0;
	ret = (float **)malloc(sizeof(float *) * 7);
	while (y < 7)
	{
		ret[y] = (float *)malloc(sizeof(float) * 7);
		x = 0;
		while (x < 7)
		{
			ret[y][x] = model[y][x];
			printf("%.f ", ret[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (ret);
}

static int **layout_init(char layout[3][3])
{
	int	y;
	int	x;
	int	**ret;

	y = 0;
	ret = (int **)malloc(sizeof(int *) * 3);
	while (y < 3)
	{
		ret[y] = (int *)malloc(sizeof(int) * 3);
		x = 0;
		while (x < 3)
		{
			if (layout[y][x] == '*')
				ret[y][x] = 1;
			else
				ret[y][x] = 0;
			x++;
		}
		y++;
	}
	return (ret);
}

int	main(void)
{
	t_sqrt		**board;
	t_sqrt		**board_cpy;
	t_filler	f;
	int			i;
	float		score;
	t_point		point;
	t_piece		pc;
	t_point		best_position;
	char		pc_layout[3][3] = 
	{
		{'*','*','.'},
		{'.','*','.'},
		{'.','.','.'}
	};

	pc.layout = layout_init(pc_layout);
	f.mask = mask_init();
	pc.x_max = 2;
	pc.y_max = 2;
	pc.free_columns = 0;
	pc.free_lines = 0;
	point.x = 2;
	point.y = 6;

	f.x_max = 30;
	f.y_max = 30;
	board = board_random(f, 0);
	board_cpy = board_random(f, 0);

	//printf("BOARD\n"); fflush(stdout);
	//print_board_old(f.x_max, f.y_max, board);
/*	printf("BOARD CPY\n"); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board_cpy);
	board_cpy_reset(board, &board_cpy, f);
	printf("BOARD\n"); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board);
	printf("BOARD CPY\n"); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board_cpy);*/
	//printf("is_placeable = %d\n", is_placeable(board, pc, point, f)); fflush(stdout);

	//board[0][0].possession = P2;
	//board[0][0].p1_distance = 500;
	//board[0][0].p2_distance = 0;
	/*board[5][0].possession = P1;
	board[5][0].p1_distance = 0;
	board[5][0].p2_distance = 500;
	board[5][1].possession = P1;
	board[5][1].p1_distance = 0;
	board[5][1].p2_distance = 500;
	board[5][2].possession = P1;
	board[5][2].p1_distance = 0;
	board[5][2].p2_distance = 500;
	board[4][2].possession = P1;
	board[4][2].p1_distance = 0;
	board[4][2].p2_distance = 500;
	board[3][2].possession = P1;
	board[3][2].p1_distance = 0;
	board[3][2].p2_distance = 500;
	board[2][2].possession = P1;
	board[2][2].p1_distance = 0;
	board[2][2].p2_distance = 500;
	board[1][2].possession = P1;
	board[1][2].p1_distance = 0;
	board[1][2].p2_distance = 500;*/
	/*board[0][2].possession = P1;
	board[0][2].p1_distance = 0;
	board[0][2].p2_distance = 500;*/

	/*board[8][8].possession = P2;
	board[8][8].p1_distance = 500;
	board[8][8].p2_distance = 0;
	board[0][15].possession = P2;
	board[0][15].p1_distance = 500;
	board[0][15].p2_distance = 0;*/
	board[5][5].possession = P2;
	board[5][5].p1_distance = 500;
	board[5][5].p2_distance = 0;
	board[29][29].possession = P1;
	board[29][29].p1_distance = 0;
	board[29][29].p2_distance = 500;
	/*board[19][19].possession = P1;
	board[19][19].p1_distance = 0;
	board[19][19].p2_distance = 500;*/
	/*board[0][15].possession = P1;
	board[0][15].p1_distance = 0;
	board[0][15].p2_distance = 500;
	board[15][0].possession = P1;
	board[15][0].p1_distance = 0;
	board[15][0].p2_distance = 500;*/

	print_board_old(f.x_max, f.y_max, board);
	i = 0;
	while (i++ < 1000)
	{
		boundary_draw_new(board, &f);
		print_board_old(f.x_max, f.y_max, board);
		//board_print(board, f);
		getchar();
		//if (i % 2)
		//{
			//pc = get_piece(pc);
			best_position = get_best_position(board, &board_cpy, pc, &f);
			//printf("best_position - x: %d, y: %d\n", best_position.x, best_position.y);
			piece_write(&board, pc, best_position);
		//}
		//else
		//{
		//	best_position = get_best_position_for_p2(board, &board_cpy, pc, &f);
		//	piece_write_for_p2(&board, pc, best_position);
		//}
	}
	printf("score = %.2f / %d\n", board_score_calc(board, f), f.x_max * f.y_max); fflush(stdout);
	print_board_old(f.x_max, f.y_max, board);
	return (0);
}
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
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
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
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
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
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
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
			//if (p2_d_tmp > PERIMETRE){p2_d_tmp = 10000;}
			//if (p1_d_tmp > PERIMETRE){p1_d_tmp = 10000;}
			if (/*p1_d_tmp < PERIMETRE &&*/ p1_d_tmp < board[y][x].p1_distance && possession != P2)
				board[y][x].p1_distance = p1_d_tmp;
			if (p2_d_tmp < PERIMETRE && p2_d_tmp < board[y][x].p2_distance && possession != P1)
				board[y][x].p2_distance = p2_d_tmp;
			y--;
		}
		x++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 09:03:11 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


#include <fcntl.h>
#include <unistd.h>

t_sqrt tile_init(t_filler game_settings, char position)
{
	t_sqrt tile;

	tile.p1_distance = game_settings.x_max * game_settings.y_max;
	tile.p2_distance = game_settings.x_max * game_settings.y_max;
	if (((position == 'O' || position == 'o') && game_settings.opponent == P1)
			|| (position == 'X' | position == 'x' && game_settings.opponent == P2))
	{
		tile.possession = P2;
		tile.p2_distance = 0;
	}
	else
	{
		tile.possession = P1;
		tile.p1_distance = 0;
	}
	return (tile);
}

t_sqrt **board_init(t_sqrt **board, t_filler game_settings, int time)
{
	char	buf[4096];
	int		x;
	int		y;

	y = 0;
	if (time)
		fast_gnl(0, &buf);
	fast_gnl(0, &buf);
	while (y < game_settings.y_max)
	{
		fast_gnl(0, &buf);
		x = 0;
		while (x < game_settings.x_max)
		{
			if (buf[x + 4] != '.' && board[y][x].possession > 0
							&& board[y][x].possession < 1)
				board[y][x] = tile_init(game_settings, buf[x + 4]);
			x++;
		}
		y++;
	}
	return (board);
}

t_filler	get_game_settings()
{
	char		buf[4096];
	t_filler	game_settings;
	int			i;

	i = 0;
	fast_gnl(0, &buf);
	if (ft_strstr(buf, "p1"))
		game_settings.opponent = P2;
	else
		game_settings.opponent = P1;
	while (!(ft_strstr(buf, "Plateau")))
		fast_gnl(0, &buf);
	while (buf[i] && !(ft_isdigit(buf[i])))
		i++;
	game_settings.y_max = ft_atoi(&buf[i]);
	while (buf[i] && (ft_isdigit(buf[i])))
		i++;
	game_settings.x_max = ft_atoi(&buf[i]);
	return (game_settings);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 01:20:17 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/17 01:38:44 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

float	calc_score(t_sqrt **board, t_filler f)
{
	int		x;
	int		y;
	float	score;

	score = 0;
	y = 0;
	while (y < f.y_max)
	{
		x = 0;
		while (x < f.x_max)
		{
			score += board[y][x].possession;
			x++;
		}
		y++;
	}
	return (score);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:58:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 09:14:35 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int	fast_gnl(int fd, char (*line)[4096])
{
	static char					buf[4096];
	int							i;
	int							rd;

	rd = 0;
	i = 0;
	if (!(ft_strchr(buf, '\n')))
		if ((rd = read(fd, buf, 4095) == -1))
			return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	ft_memcpy((*line), buf, i);
	if (buf[i] && i == 0 && buf[i] == '\n')
		(*line)[2] = 0;
	else
		(*line)[i] = 0;
	ft_memcpy(buf, buf + i + 1, 4096 - i - 1);
	return (ft_strlen(*line));
}

/*

int main(int argc, char **argv)
{
	char	*line;
	char	buf[4096];
	int		ret;
	int		fd = open("/Users/lazrossi/Documents/42/filler/Makefile", O_RDONLY);

	(void)argv;
	ret = 1;
	if (argc == 2)
	{
		while ((ret))
		{
			ret = fast_gnl(fd, &buf);
			printf("%s\n", buf);
		}
		printf("%s\n", "we were in fast_gnl");
	}
	else 
	{
		while ((ret))
		{
			ret = get_next_line(fd, &line);
			printf("%s\n", line);
		}
	}
	close(fd);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:02:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/26 01:23:19 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

int	check_empty_column(t_piece piece)
{
	int free_columns;
	int	i;

	free_columns = 0;
	while (free_columns < piece.x_max - 1)
	{
		i = -1;
		while (++i < piece.y_max)
			if (piece.layout[i][free_columns] == 1)
				return (free_columns);
		free_columns++;
	}
	return (free_columns);
}

void	swap_columns(t_piece piece, int free_columns)
{
	int i;
	int j;

	i = 0;
		while (i < piece.y_max)
		{
			j = 0;
			while (j + free_columns < piece.x_max)
			{
				piece.layout[i][j] =
				piece.layout[i][j + free_columns];
				piece.layout[i][j + free_columns] =
				(j + free_columns * 2  < piece.x_max) ?
				piece.layout[i][j + free_columns * 2] : 0;
				j++;
			}
			i++;
		}
}

int check_empty_line(t_piece piece)
{
	int free_lines;
	int i;

	free_lines = 0;
	while (free_lines < piece.y_max)
	{
		i = -1;
		while (++i < piece.x_max)
			if (piece.layout[free_lines][i] == 1)
				return (free_lines);
		free_lines++;
	}
	return (free_lines);
}

void	swap_lines(t_piece piece, int free_lines)
{
	int i;
	int j;
	
	i = 0;
	while (i < piece.x_max)
	{
		j = 0;
		while (j + free_lines < piece.y_max)
		{
			piece.layout[j][i] =
			piece.layout[j + free_lines][i];
			piece.layout[j + free_lines][i] =
			(j + free_lines * 2  < piece.y_max) ? 
			piece.layout[j + free_lines * 2][i] : 0;
			j++;
		}
		i++;
	}
}

t_piece norm_piece(t_piece piece)
{
	if ((piece.free_columns = check_empty_column(piece)))
		swap_columns(piece, piece.free_columns);
	if ((piece.free_lines = check_empty_line(piece)))
		swap_lines(piece, piece.free_lines);
	piece.x_max -= piece.free_columns;
	piece.y_max -= piece.free_lines;
	return (piece);
}

void	print_piece(t_piece piece)
{
	int i;
	int j;

//	ft_printf("[[~/Documents/42/filler/debug.txt]]\nDEBUG");
	ft_printf("[[~/Documents/42/filler/piece.txt]]\nthis is piece.y_max : %d\nthis is piece.x_max : %d\n", piece.y_max, piece.x_max);
	i = 0;
	while (i < piece.y_max)
	{
		j = 0;
		while (j < piece.x_max)
		{
			ft_printf("[[~/Documents/42/filler/piece.txt]]%d", piece.layout[i][j]);
			j++;
		}
			ft_printf("[[~/Documents/42/filler/piece.txt]]\n");
		i++;
	}
	ft_printf("[[~/Documents/42/filler/piece.txt]]\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/01 16:32:25 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	print_board_old(int x_max, int y_max, t_sqrt **board);

static void		position_update(t_point *position, t_direction direction)
{
	int	x_diff;
	int	y_diff;

	x_diff = 0;
	y_diff = 0;
	if (direction == up)
		y_diff--;
	else if (direction == right)
		x_diff++;
	else if (direction == down)
		y_diff++;
	else if (direction == left)
		x_diff--;
	position->x += x_diff;
	position->y += y_diff;
}

static void		position_init(t_point *position, int x, int y)
{
	position->x = x;
	position->y = y;
}

static int		ft_filler_abs(int x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

static float	get_possession(t_sqrt **board, t_point o, t_filler filler)
{
	t_point		pt;
	t_direction	direction;
	int			i;
	int			i_lim;
	float		distance_p1;
	float		distance_p2;
	int			time;

	i_lim = 1;
	position_init(&pt, o.x, o.y);
	distance_p1 = -1;
	distance_p2 = -1;
	direction = up;
	while (distance_p1 < 0 || distance_p2 < 0)
	{
		time = 0;
		while (time++ < 2)
		{
			i = 0;
			while (i++ < i_lim)
			{
				position_update(&pt, direction);
				//				printf("position px %d py %d\n", pt.x, pt.y);
				if (pt.x >= 0 && pt.x < filler.x_max && pt.y >= 0 && pt.y < filler.y_max)
				{
					if (board[pt.y][pt.x].possession == P1 && distance_p1 == -1)
					{
						distance_p1 = (ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)) * 2;
						//						printf("distance p1: %d - px %d - py %d - pox %d - poy %d\n", (int)distance_p1, pt.x, pt.y, o.x, o.y);
					}
					else if (board[pt.y][pt.x].possession == P2 && distance_p2 == -1)
					{
						distance_p2 = (ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)) * 2;
						//						printf("distance p2: %d - px %d - py %d - pox %d - poy %d\n", (int)distance_p2, pt.x, pt.y, o.x, o.y);
					}
				}
			}
			direction = (direction + 1) % 4;
		}
		i_lim++;
	}
	return (distance_p1 / (distance_p1 + distance_p2));
}

t_point t_point_init(int x, int y)
{
	t_point point;
	point.x = x;
	point.y = y;
	return (point);
}

void	possession_update_from_point(t_sqrt **board, t_point o, t_filler filler, int player_side)
{
	t_point		pt;
	float		distance;

	pt.y = 0;
	while (pt.y < filler.y_max)
	{
		pt.x = 0;
		while (pt.x < filler.x_max)
		{
			if (board[pt.y][pt.x].possession != P1 && board[pt.y][pt.x].possession != P2)
			{
				if (player_side < 0 && board[pt.y][pt.x].p1_distance >
						(distance = ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)))
					board[pt.y][pt.x].p1_distance = distance;
				else if (player_side > 0 && board[pt.y][pt.x].p2_distance >
						(distance = ft_filler_abs(pt.y - o.y) + ft_filler_abs(pt.x - o.x)))
					board[pt.y][pt.x].p2_distance = distance;
			}
			pt.x++;
		}
		pt.y++;
	}
}

void	distance_update_from_point(t_sqrt **board, t_point o, t_filler filler, int player_side)
{
	int			x;
	int			y;
	float		distance;
	float		possession;

	y = 0;
	while (y < filler.y_max)
	{
		x = 0;
		while (x < filler.x_max)
		{
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
			{
				distance = ft_filler_abs(y - o.y) + ft_filler_abs(x - o.x);
				if (player_side < 0  && board[y][x].p1_distance > distance)
					board[y][x].p1_distance = distance;
				else if (player_side > 0 && board[y][x].p2_distance > distance)
					board[y][x].p2_distance = distance;
			}
			x++;
		}
		y++;
	}
}

void	possession_update(t_sqrt **board, t_filler filler)
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
			if (possession != P1 && possession != P2)
				board[y][x].possession = p2_d / (p2_d + board[y][x].p1_distance);
			x++;
		}
		y++;
	}
}

void    board_possession_update(t_sqrt **board, t_filler *gs)
{
	int				x;
	int				y;
	float			p2_d_tmp;
	float			possession;
	int		time;
	const int		gs_y_max = gs->y_max;
	const int		gs_x_max = gs->x_max;

	time = 0;
	y = 0;
	gs->fill_mode = 1;
	while (y < gs_y_max)
	{
		x = 0;
		while (x < gs_x_max)
		{
			p2_d_tmp = board[y][x].p2_distance;
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
			board[y][x].possession = p2_d_tmp / (p2_d_tmp + board[y][x].p1_distance);
			if (possession < 0.8 && possession > 0.2)
			  time++;
			  if (time > (gs->x_max * gs->y_max) / 20)
			  gs->fill_mode = 0;
			x++;
		}
		y++;
	}
}

void    board_distance_reset(t_sqrt **board, t_filler gs)
{
	int			x;
	int			y;
	float		possession;
	const int	gs_y_max = gs.y_max;
	const int	gs_x_max = gs.x_max;

	y = 0;
	while (y < gs_y_max)
	{
		x = 0;
		while (x < gs_x_max)
		{
			possession = board[y][x].possession;
			if (possession != P1 && possession != P2)
			{
				board[y][x].p1_distance = 100000;
				board[y][x].p2_distance = 100000;
			}
			x++;
		}
		y++;
	}
}

void    board_update(t_sqrt **board, t_filler *gs)
{
	int i;
	i = 0;
	board_distance_reset(board, *gs);
	while (i++ < 1)
	{
		board_distance_update_1(board, *gs);
		board_distance_update_2(board, *gs);
		board_distance_update_3(board, *gs);
		board_distance_update_4(board, *gs);
		board_distance_update_5(board, *gs);
		board_distance_update_6(board, *gs);
		board_distance_update_7(board, *gs);
		board_distance_update_8(board, *gs);
	}
	board_possession_update(board, gs);
}
/*
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
*/
float   board_score_calc(t_sqrt **board, t_filler gs)
{
	float score;
	int x;
	int y;

	score = 0;
	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			score += board[y][x].possession;
			x++;
		}
		y++;
	}
	return (score);
}

float   score_update_for_p2(t_sqrt ***board_cpy, float *high_score, t_filler *gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, *gs);
	//printf("score = %.f hscore = %.f\n", score, *high_score); fflush(stdout);
	if (score < *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
}

float   score_update(t_sqrt ***board_cpy, float *high_score, t_filler *gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, *gs);
	//printf("score = %.f hscore = %.f\n", score, *high_score); fflush(stdout);
	if (score > *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
}

int     is_placeable_for_p2(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
{
	int     x;
	int     y;
	float   possession;
	int		mixed;

	mixed = 0;
	if (pc.x_max > gs.x_max - o.x || pc.y_max > gs.y_max - o.y)
		return (0);
	y = 0/*pc.free_columns*/;
	while (y < pc.y_max)
	{
		x = 0/*pc.free_lines*/;
		while (x < pc.x_max)
		{
			possession = board[o.y + y][o.x + x].possession;
			//printf("%.f ", possession); fflush(stdout);
			if (pc.layout[y][x] == 1)
			{
				if (possession == P2)
					mixed++;
				else if (possession == P1)
					return (0);
			}
			x++;
		}
		//printf("\n"); fflush(stdout);
		y++;
	}
	//printf("mixed: %d\n", mixed); fflush(stdout);
	return ((mixed == 1));
}

int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
{
	int     x;
	int     y;
	float   possession;
	int		mixed;

	mixed = 0;
	if (pc.x_max > gs.x_max - o.x || pc.y_max > gs.y_max - o.y)
		return (0);
	y = pc.free_columns;
	while (y < pc.y_max)
	{
		x = pc.free_lines;
		while (x < pc.x_max)
		{
			possession = board[o.y + y][o.x + x].possession;
			if (pc.layout[y][x] == 1)
			{
				if (possession == P1)
					mixed++;
				else if (possession == P2)
					return (0);
				if (mixed > 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	return ((mixed == 1));
}
/*
   int     is_placeable(t_sqrt **board, t_piece pc, t_point o, t_filler gs)
   {
   int     x;
   int     y;
   float   possession;
   int		mixed;

   mixed = 0;
   if (pc.x_max > gs.x_max - o.x || pc.y_max > gs.y_max - o.y)
   return (0);
   y = pc.free_columns;
   while (y < pc.y_max)
   {
   x = pc.free_lines;
   while (x < pc.x_max)
   {
//printf("%.f ", possession); fflush(stdout);
//printf("%.f", possession); fflush(stdout);
if (pc.layout[y][x] == 1 && gs.mask[(o.y + y) % 7][(o.x + x) % 7] == 0)
{
possession = board[o.y + y][o.x + x].possession;
if (possession == P1)
mixed++;
else if (possession == P2)
return (0);
}
else if (pc.layout[y][x] == 1 && gs.mask[(o.y + y) % 7][(o.x + x) % 7] == 1)
return (0);
x++;
}
//printf("\n"); fflush(stdout);
y++;
}
//printf("mixed: %d\n", mixed); fflush(stdout);
return ((mixed == 1));
}
*/
void     piece_write_for_p2(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
	int     x;
	int     y;

	y = 0;
	while (y < pc.y_max)
	{
		x = 0;
		while (x < pc.x_max)
		{
			if (pc.layout[y][x] == 1)
			{
				(*board_cpy)[o.y + y][o.x + x].possession = 0;
				(*board_cpy)[o.y + y][o.x + x].p1_distance = 99999;
				(*board_cpy)[o.y + y][o.x + x].p2_distance = 0;
			}
			x++;
		};
		y++;
	}
}

void     piece_write(t_sqrt ***board_cpy, t_piece pc, t_point o)
{
	int     x;
	int     y;

	y = 0;
	while (y < pc.y_max)
	{
		x = 0;
		while (x < pc.x_max)
		{
			if (pc.layout[y][x] == 1)
			{
				(*board_cpy)[o.y + y][o.x + x].possession = 1;
				(*board_cpy)[o.y + y][o.x + x].p1_distance = 0;
				(*board_cpy)[o.y + y][o.x + x].p2_distance = 99999;
			}
			x++;
		};
		y++;
	}
}

void    board_to_board(t_sqrt **src, t_sqrt ***dest, t_filler gs)
{
	int     x;
	int     y;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
		{
			(*dest)[y][x].possession = src[y][x].possession;
			(*dest)[y][x].p1_distance = src[y][x].p1_distance;
			(*dest)[y][x].p2_distance = src[y][x].p2_distance;
			x++;
		};
		y++;
	}
}

t_point get_best_position_from_zone(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs, t_point zone)
{
	t_point			pt;
	t_point			memo;
	float			high_score;
	const int		x_lim = (zone.x + 5 < gs->x_max) ? zone.x + 5 : gs->x_max;
	const int		y_lim = (zone.y + 5 < gs->y_max) ? zone.y + 5 : gs->y_max;

	memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = (zone.y - 5 > -1) ? zone.y - 5 : -1;
	while (++pt.y < y_lim)
	{
		pt.x = (zone.x - 5 > -1) ? zone.x - 5 : -1;
		while (++pt.x < x_lim)
		{
			if (is_placeable(board, pc, pt, *gs))
			{
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
					memo = t_point_init(pt.x, pt.y);
			}
		}
	}
	return (memo);
}

t_point get_best_zone(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			pt;
	t_point			memo;
	float			high_score;
	//int				opti;
	int				placeable;

	memo.x = 0;
	memo.y = 0;
	placeable = 4;
	high_score = 0;
	pt.y = -1;
	while (++pt.y < gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < gs->x_max)
		{
			if (is_placeable(board, pc, pt, *gs) && !(++placeable % 5))
			{
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
				{
					memo.x = pt.x;
					memo.y = pt.y;
				}
			}
		}
	}
	return (memo);
}

t_point get_best_position_std(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			pt;
	t_point			memo;
	float			high_score;

	memo = t_point_init(0, 0);
	high_score = 0;
	pt.y = -1;
	while (++pt.y < gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < gs->x_max)
		{
			if (is_placeable(board, pc, pt, *gs))
			{
				if (gs->fill_mode == 1)
					return (pt);
				board_to_board(board, board_cpy, *gs);
				piece_write(board_cpy, pc, pt);
				if (score_update(board_cpy, &high_score, gs))
					memo = t_point_init(pt.x, pt.y);
			}
		}
	}
	return (memo);
}

t_point get_best_position(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point			memo;

	memo.x = 0;
	memo.y = 0;
	if (OPTI)
	{
		memo = get_best_zone(board, board_cpy, pc, gs);
		memo = get_best_position_from_zone(board, board_cpy, pc, gs, memo);
	}
	else
	{
		memo = get_best_position_std(board, board_cpy, pc, gs);
	}
	return (memo);
}

t_point get_best_position_for_p2(t_sqrt **board, t_sqrt ***board_cpy, t_piece pc, t_filler *gs)
{
	t_point pt;
	t_point memo;
	float   high_score;

	pt.y = -1;
	high_score = gs->x_max * gs->y_max;
	while (++pt.y < gs->y_max)
	{
		pt.x = -1;
		while (++pt.x < gs->x_max)
		{
			if (is_placeable_for_p2(board, pc, pt, *gs))
			{
				//printf("placeable - x: %d, y: %d\n", pt.x, pt.y); fflush(stdout);
				board_to_board(board, board_cpy, *gs);
				piece_write_for_p2(board_cpy, pc, pt);
				if (score_update_for_p2(board_cpy, &high_score, gs))
				{
					//printf("new best position - score: %.2f\n", high_score); fflush(stdout);
					memo.x = pt.x;
					memo.y = pt.y;
				}
			}
		}
	}
	return (memo);
}

void		boundary_draw_old(t_sqrt **board, t_filler filler)
{
	//	printf("DRAW IN\n"); fflush(stdout);
	t_point	pt;
	float	possession;

	pt.y = 0;
	while (pt.y < filler.y_max)
	{
		pt.x = 0;
		while (pt.x < filler.x_max)
		{
			possession = board[pt.y][pt.x].possession;
			//printf("X: %d Y: %d Possession: %.2f\n", pt.x, pt.y, possession); fflush(stdout);
			if (possession != P1 && possession != P2)
				board[pt.y][pt.x].possession = get_possession(board, pt, filler);
			//			printf("Possession: %.2f\n", possession); fflush(stdout);
			//`			print_board_old(filler.x_max, filler.y_max, board);
			//			getchar();
			pt.x++;
		}
		pt.y++;
	}
}

void		boundary_draw(t_sqrt **board, t_filler filler)
{
	t_point	pt;
	float	possession;

	pt.y = 0;
	while (pt.y < filler.y_max)
	{
		pt.x = 0;
		while (pt.x < filler.x_max)
		{
			possession = board[pt.y][pt.x].possession;
			if (possession == P1 || possession == P2)
				distance_update_from_point(board, pt, filler, (possession < 0) * 2 - 1);
			pt.x++;
		}
		pt.y++;
	}
	possession_update(board, filler);
}

void		boundary_draw_new(t_sqrt **board, t_filler *f)
{
	//board_print(*board, f);
	//board_print(*board, f);
	board_update(board, f);
	//board_print(*board, f);
}
#include <stdio.h>
#include <stdlib.h>

#define bloc_len 3
#define x_max 5
#define y_max 3

typedef struct   s_point
{
    int x;
    int y;
}               t_point;

int step_maj(t_point *step)
{
    step->x++;
    if (step->x * bloc_len >= x_max)
    {
        step->x = 0;
        step->y++;
        if (step->y * bloc_len >= y_max)
            return (0);
    }
    return (1);
}

t_point t_point_init(int x, int y)
{
    t_point point;
    point.x = x;
    point.y = y;
    return (point);
}

int main()
{
    int tab[y_max][x_max];
    t_point pt;
    t_point step;

    step = t_point_init(-1, 0);
    while (step_maj(&step))
    {
            pt.y = step.y * bloc_len - 1;
            while (++pt.y < (step.y + 1) * bloc_len && pt.y < y_max && (pt.x = step.x * bloc_len - 1))
                while (++pt.x < (step.x + 1) * bloc_len && pt.x < x_max)
                {
                    printf("y: %d - x: %d\n", pt.y, pt.x);
                }
    }
    return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:02:34 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/26 08:37:37 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/19 15:57:46 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/*

int		try_insert(t_piece piece, t_sqrt **board_tmp, char **location, int x, int y)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	tmp = NULL;
	while (i < piece.free_lines)
	{
		j = 0;
		while (j < piece.free_columns)
		{
			if (piece.piece_layout[i][i] && board_tmp[x + i][y + j].possession == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (!(tmp = ft_itoa(x - piece.free_columns)))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	if (!(tmp = ft_strdup(" ")))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	if (!(tmp = ft_itoa(y - piece.free_lines)))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	if (!(tmp = ft_strdup("\n")))
		return (0);
	if (!(*location = ft_strjoinfree(location, &tmp, 'B')))
		return (0);
	return (1);
}

void	put_piece(t_sqrt **board,t_piece piece, t_filler game_settings)
{
	int x;
	int y;
	char *location;
	t_sqrt **board_tmp;

	x = 0;
	location = NULL;
	(void)board;
	if (!(board_tmp = board_malloc(game_settings)))
		return ;
	while (x < game_settings.y_max - piece.free_lines)
	{
		y = 0;
		while (y < game_settings.x_max - piece.free_columns)
		{
			board_tmp = board_init(board_tmp, game_settings);
			if (board_tmp[x][y].possession == 0)
			{
				if (try_insert(piece, board_tmp, &location, x, y))
				{
					ft_putstr(location);
					return ;
				}
			}
			y++;
		}
		x++;
	}
}
*/

int	main(void)
{
	t_sqrt		**board;
	t_sqrt		**board_cpy;
	t_filler	game_settings;
	t_point		best_position;
	t_piece		piece;

	board = NULL;
	piece.layout = NULL;
	game_settings = get_game_settings();
	(void)best_position;
	(void)board_cpy;
	if (!(board = board_malloc(game_settings)))
		return (1);
	if (!(board_cpy = board_malloc(game_settings)))
		return (1);
	//board_print(board, game_settings);
	//print_board_old(gamoe_settings.x_max, game_settings.y_max, board);
	int go;

	go = 0;
	while (1)
	{
	board = board_init(board, game_settings, go);
	go = 1;
	//board_print(board, game_settings);
//	print_board_old(game_settings.x_max, game_settings.y_max, board);
	get_piece(&piece);
	//ft_printf("[[~/Documents/42/filler/test.txt]] '%s' ret = %d\n", buf, ret);

	//print_piece(piece);
	board_update(board, &game_settings);
	//board_print(board, game_settings);
	//print_board_old(game_settings.x_max, game_settings.y_max, board);
	best_position = get_best_position(board, &board_cpy, piece, &game_settings);
	//ft_printf("[[~/Documents/42/filler/test.txt]] %d %d \n", best_position.x, best_position.y);
	//print_board_old(game_settings.x_max, game_settings.y_max, board);
	//printf("\nx_max = %d y_max = %d\n", game_settings.x_max, game_settings.y_max); fflush(stdout);
	//printf("game_settings - opponent: %d\n", game_settings.opponent); fflush(stdout);
	ft_printf("[[~/Documents/42/filler/test.txt]]%d %d\n", best_position.y, best_position.x); fflush(stdout);
	printf("%d %d\n", best_position.y, best_position.x); fflush(stdout);
	}
//	if (game_settings.opponent == 'X')
		//printf("debug"); fflush(stdout);
//		board = board_init(board, game_settings);
		//print_board(game_settings.x_max, game_settings.y_max, board);
//		piece = get_piece(piece);
//		print_piece(piece);
//		put_piece(board, piece, game_settings);
//		printf("%d %d\n", 3, 3); fflush(stdout);
	//board[1][1].possession = 0;
	//board[1][2].possession = 0;
	//board[1][3].possession = 0;
	//board[0][3].possession = 0;
	//board[0][4].possession = 0;
	//board[f.y_max - 2][f.x_max - 2].possession = 1;
	//board[f.y_max - 3][f.x_max - 3].possession = 1;
	//board[f.y_max - 4][f.x_max - 4].possession = 1;
	//board[f.y_max - 5][f.x_max - 5].possession = 1;
	//board[f.y_max - 6][f.x_max - 6].possession = 1;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloced_structures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:32:54 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/26 03:54:50 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

t_sqrt	**board_malloc(t_filler game_settings)
{
	int		y;
	int		x;
	t_sqrt	**board;

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
			board[y][x].possession = 0.5;
			board[y][x].p1_distance = game_settings.y_max * game_settings.x_max;
			board[y][x].p2_distance = game_settings.y_max  *game_settings.x_max;
			x++;
		}
		y++;
	}
	return (board);
}

void	get_piece(t_piece *piece)
{
	char	buf[4096];
	int		x;
	int		y;

	int		ret;

	y = -1;
	while (!ft_strstr(buf, "Piece"))
	{
		ret = fast_gnl(0, &buf);
		ft_printf("[[~/Documents/42/filler/test.txt]] '%s'", buf);
	}
	piece->y_max = ft_atoi(&buf[5]);
	ret = fast_gnl(0, &buf);
	ft_printf("[[~/Documents/42/filler/test.txt]] '%s'", buf);
	piece->x_max = ft_strlen(buf);
	if (piece->layout)
		ft_tabdel((void***)&piece->layout);
	if (!(piece->layout = (int**)malloc(sizeof(int *) * (piece->y_max + 1))))
		return ;
	piece->layout[piece->y_max] = NULL;
	while (++y < piece->y_max)
	{
		if (!(piece->layout[y] = (int *)malloc(sizeof(int) * (piece->x_max + 1))))
			return ;
		x = -1;
		while (++x < piece->x_max)
			piece->layout[y][x] = (buf[x] == '*');
		if (y < piece->y_max - 1)
		{
			ret = fast_gnl(0, &buf);
			ft_printf("[[~/Documents/42/filler/test.txt]] '%s'", buf);
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:58:32 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 02:26:57 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*debug*/
#include "../includes/filler.h"

void	print_board_old(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;
	float	possession;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			possession = board[y][x].possession;
			if (possession == P2)
				ft_printf("[[red]]  X  [[end]]");
			else if (possession == P1)
				ft_printf("[[blue]]  O  [[end]]");
			else if (possession < 0.5 && possession > 0)
			{
				printf("\033[35m%03.f%% \033[0m", possession * 100); fflush(stdout);
			}
			else if (possession > 0.5 && possession < 1)
			{
				printf("\033[36m%03.f%% \033[0m", possession * 100); fflush(stdout);
			}
			else
			{
				printf("%03.f%% ", possession * 100); fflush(stdout);
			}
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	print_board(int x_max, int y_max, t_sqrt **board)
{
	int		y;
	int		x;
	float	possession;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			possession = board[y][x].possession;
			if (possession == P1)
				printf("\033[31m  X  \033[0m");
			else if (possession == P2)
				printf("\033[34m  O  \033[0m");
			else if (possession < 0)
				printf("\033[35m%+04.f \033[0m", possession);
			else if (possession > 0)
				printf("\033[36m%+04.f \033[0m", possession);
			else
				printf("%+04.f ", possession);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
