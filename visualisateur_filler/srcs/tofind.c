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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/04 00:47:04 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

t_sqrt tile_init(char position)
{
	t_sqrt tile;

	tile.p1_distance = 100000;
	tile.p2_distance = 100000;
	if (position == 'O' || position == 'o')
	{
		tile.possession = P1;
		tile.p1_distance = 0;
	}
	else if (position == 'X' || position == 'x')
	{
		tile.possession = P2;
		tile.p2_distance = 0;
	}
	return (tile);
}

t_sqrt **board_init(t_sqrt **board, t_filler *game_settings)
{
	char	buf[BUFF_GNL];
	int		x;
	int		y;

	y = 0;
	while (y < game_settings->y_max)
	{
		x = 0;
		fast_gnl(0, &buf);
		if (ft_strstr(buf, "fin"))
		{
			find_winner(game_settings, buf);
			return (board);
		}
		while (x < game_settings->x_max)
		{
			if (buf[x + 4] != '.' && board[y][x].possession != -1)
				board[y][x] = tile_init(buf[x + 4]);
			x++;
		}
		y++;
		ft_memdel((void**)&buf);
	}
	return (board);
}

void	put_sentence(t_filler * gs, int player)
{
	if (player == P1)
	{
		ft_memset(gs->p1_info, 0, 1024);
		ft_memcpy(gs->p1_info, "Possession estimation for P1, ",
		ft_strlen("Possession estimation for P1, "));
	}
	else if (player == P2)
	{
		ft_memset(gs->p2_info, 0, 1024);
		ft_memcpy(gs->p2_info, "Possession estimation for P2, ",
		ft_strlen("Possession estimation for P2, "));
	}
}


void	set_player_info(char buf[BUFF_GNL], t_filler *gs, int player)
{
	char	*tmp;
	char	name[1024];

	tmp = NULL;
	put_sentence(gs, player);
	if (ft_strstr(buf, "players"))
		buf = ft_strstr(buf, "players");
	buf = ft_strstr(buf, "/");
	buf += 1;
	if (ft_strstr(buf, "."))
		tmp = ft_strstr(buf, ".");
	ft_memset(name, 0, 1024);
	if (tmp)
		ft_memcpy(name, buf, ft_strlen(buf) - ft_strlen(tmp));
	else
		ft_memcpy(name, buf, ft_strlen(buf) - 1);
	if (player == P1)
		ft_memcpy(gs->p1_info + ft_strlen(gs->p1_info), name, ft_strlen(name));
	else if (player == P2)
		ft_memcpy(gs->p2_info + ft_strlen(gs->p2_info), name, ft_strlen(name));
}

t_filler	get_game_settings()
{
	char			buf[BUFF_GNL];
	static t_filler	game_settings;
	static int 		first = 1;
	int				i;

	fast_gnl(0, &buf);
	i = 0;
	game_settings.game_over = 0;
	while (!(ft_strstr(buf, "Plateau")))
	{
		ft_memdel((void**)&buf);
		fast_gnl(0, &buf);
		if (ft_strstr(buf, "exec p1"))
			set_player_info(buf, &game_settings, P1);
		if (ft_strstr(buf, "exec p2"))
			set_player_info(buf, &game_settings, P2);
	}
	while (buf[i] && !(ft_isdigit(buf[i])))
		i++;
	game_settings.y_max = ft_atoi(&buf[i]);
	while (buf[i] && (ft_isdigit(buf[i])))
		i++;
	game_settings.x_max = ft_atoi(&buf[i]);
	first = 0;
	ft_memdel((void**)&buf);
	return (game_settings);
}
#include "../includes/filler.h"

void    board_update(t_sqrt **board, t_filler *gs)
{
	int i;
	i = 0;
	board_distance_reset(board, *gs);
	board_distance_update_1(board, *gs);
	board_distance_update_2(board, *gs);
	board_distance_update_3(board, *gs);
	board_distance_update_4(board, *gs);
	board_distance_update_5(board, *gs);
	board_distance_update_6(board, *gs);
	board_distance_update_7(board, *gs);
	board_distance_update_8(board, *gs);
	board_possession_update(board, *gs);
	get_total_possession(board, gs);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:58:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/02 00:06:42 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/filler.h"
#include <stdio.h>
/*
int	fast_gnl(int fd, char (*line)[4096])
{
	static char				buf[BUFF_GNL];
	int						i;
	int						rd;

	rd = 0;
	i = 0;
	if (!(ft_strchr(buf, '\n')))
		if ((rd = read(fd, buf, BUFF_GNL - 1) == -1))
			return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	ft_memcpy((*line), buf, i);
	if (buf[i] && i == 0 && buf[i] == '\n')
		(*line)[2] = 0;
	else
		(*line)[i] = 0;
	ft_memcpy(buf, buf + i + 1, BUFF_GNL - i - 1);
	return (ft_strlen(*line));
}

int			fast_gnl(const int fd, char (*line)[BUFF_GNL])
{
	char	tmp;
	int		i;

	i = 0;
	tmp = 0;
	while (tmp != '\n' && i < BUFF_GNL - 1)
	{
		read(fd, &tmp, 1);
		(*line)[i] = tmp;
		i++;
	}
	(*line)[i] = '\0';
	return (1);
}
*/

int			fast_gnl(const int fd, char (*line)[4096])
{
	int				rd;
	char			buf[BUFF_GNL + 1];
	static	char	s[BUFF_GNL * 4];
	char			*tmp;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	rd = 1;
	while (!(ft_strchr(s, '\n')))
	{
		rd = read(fd, buf, BUFF_GNL);
		buf[rd] = 0;
		tmp = ft_strchr(s, '\0');
		ft_memcpy(tmp, buf, ft_strlen(buf));
	}
	ft_memset(*line, '\0', BUFF_GNL);
	ft_memcpy(*line, s, ft_strchr(s, '\n') - s);
	ft_memcpy(s, ft_strchr(s, '\n') + 1, ft_strlen(s));
	return ((rd > 0) || (ft_strlen(*line) > 0));
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	int		rd;
	char	line[BUFF_GNL + 1];
	char	*line2;
	int		fd = open(argv[1], O_RDONLY);

	while ((rd = fast_gnl_2(fd, &line)))
	{
		printf("rd = %d - line = \'%s\'\n", rd, line); fflush(stdout);
	}
	printf("rd = %d - line = \'%s\'\n", rd, line); fflush(stdout);
	close(fd);
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:21:22 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 08:37:15 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void    board_distance_reset(t_sqrt **board, t_filler gs)
{
	int		x;
	int		y;
	float	possession;

	y = 0;
	while (y < gs.y_max)
	{
		x = 0;
		while (x < gs.x_max)
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

float   score_update(t_sqrt ***board_cpy, float *high_score, t_filler *gs)
{
	float score;

	board_update(*board_cpy, gs);
	score = board_score_calc(*board_cpy, *gs);
	if (score > *high_score)
	{
		*high_score = score;
		return (1);
	}
	return (0);
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
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include "../includes/filler.h"
#include "../libft/libft.h"

t_mlx	set_get_mlx(t_mlx *mlx)
{
	static t_mlx mlx_linker;

	if (mlx)
		mlx_linker = *mlx;
	return (mlx_linker);
}

int		loop_filler(int necessary)
{
	(void)necessary;
	board_img_handler();
	return (1);
}

static	t_mlx	my_mlx_init(void)
{
	t_mlx	mlx;
	int		bpp;
	int		endian;
	int		size_line;

	if (!(mlx.mlx = mlx_init()))
		ft_myexit("malloc error");
	if (!(mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "Filler")))
		ft_myexit("malloc error");
	if (!(mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE)))
		ft_myexit("malloc error");
	if (!(mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
					&bpp, &size_line, &endian)))
		ft_myexit("malloc error");
	set_get_mlx(&mlx);
	board_img_handler();
	return (mlx);
}



void	mlx_put_winner(t_mlx mlx, t_filler gs)
{
	char	winner[1024];
	char	*result;

	ft_memset(winner, 0, 1024);
	result = NULL;
	result = ft_itoa(gs.end_score);
	if (gs.game_over == P1 + 1)
		ft_memcpy(winner, gs.p1_info + 30, ft_strlen(gs.p1_info + 30)); 
	if (gs.game_over == P2 + 1)
		ft_memcpy(winner, gs.p2_info + 30, ft_strlen(gs.p2_info + 30)); 
	ft_memcpy(winner + ft_strlen(winner), " won by : ",
	ft_strlen(" won by : ")); 
	ft_memcpy(winner + ft_strlen(winner), result, ft_strlen(result));
	ft_memdel((void**)&result);
	mlx_string_put(mlx.mlx, mlx.win,
	(X_SIZE - (ft_strlen(winner) * 10)) / 2, 32, WIN_CO, winner);
}

void	board_img_handler(void)
{
	t_mlx			mlx;
	static t_sqrt	**board = NULL;
	static t_filler	game_settings;
	static int		first = 1;

	mlx = set_get_mlx(NULL);
	if (first)
	{
		game_settings = get_game_settings();
		if (!(board = board_malloc(game_settings)))
			return ;
		first = 0;
	}
	pass_pieces_or_find_winner(&game_settings);
	if (!game_settings.game_over)
	{
		board = board_init(board, &game_settings);
		board_update(board, &game_settings);
	}
	display_pieces(game_settings, board, &(mlx.screen_data)); 
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	put_player_info(mlx, game_settings, P1);
	put_player_info(mlx, game_settings, P2);
	if (game_settings.game_over)
		mlx_put_winner(mlx, game_settings);
}

int		draw(void)
{
	static	t_mlx	mlx;
	static	int		initalize = 0;

	if (!initalize)
	{
		mlx = my_mlx_init();
		initalize = 1;
	}
	mlx_loop_hook(mlx.mlx, loop_filler, 0);
	mlx_loop(mlx.mlx);
	return (0);
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

int	main(void)
{
	draw();
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
			board[y][x].possession = -1;
			board[y][x].p1_distance = game_settings.y_max * game_settings.x_max;
			board[y][x].p2_distance = game_settings.y_max  *game_settings.x_max;
			x++;
		}
		y++;
	}
	return (board);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_pieces_or_find_winner.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 00:39:00 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/04 00:45:06 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	find_winner(t_filler *game_settings, char buf[BUFF_GNL])
{
	int				p1_score;
	int				p2_score;
	char			tmp[BUFF_GNL];

	p1_score = ft_atoi(&buf[9]);
	ft_memdel((void**)&buf);
	fast_gnl(0, &tmp);
	p2_score = ft_atoi(&tmp[9]);
	if (p1_score > p2_score)
	{
		game_settings->game_over = P1 + 1;
		game_settings->end_score = p1_score - p2_score;
	}
	else
	{
		game_settings->game_over = P2 + 1;
		game_settings->end_score = p2_score - p1_score;
	}
	return ;
}

void	pass_pieces_or_find_winner(t_filler *game_settings)
{
	char			buf[BUFF_GNL];

	while (fast_gnl(0, &buf) && !(ft_strstr(buf, "Plateau")))
	{
		if (ft_strstr(buf, "fin"))
			find_winner(game_settings, buf);
		ft_memdel((void**)&buf);
	}
	fast_gnl(0, &buf);
	if (ft_strstr(buf, "fin"))
		find_winner(game_settings, buf);
	ft_memdel((void**)&buf);
}
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
		while (++x  < X_SIZE / gs.x_max - 1)
		{
			if (player == P1)
				(*screen)[where_to + x] = VIOLET; 
			else if (player == P2)
				(*screen)[where_to + x] = CYAN;
		}
		where_to += X_SIZE;
	}
}

void	screen_fill_possession(int **screen, t_sqrt tile, int where_to, t_filler gs)
{
	int					x;
	int 				y;
	float 				possession;
	t_color_compound	violet;
	t_color_compound	tmp;

	y = -1;
	possession = (float)(tile.p2_distance /
			(tile.p2_distance + tile.p1_distance));
	violet = ft_decompose_color(VIOLET);
	tmp = violet;
	while (++y < (Y_SIZE - BOARD) / gs.y_max - 1)
	{
		x = -1;
		while (++x  < X_SIZE / gs.x_max - 1)
		{
			violet = tmp;
			violet.red = (int)((float)violet.red * possession) / 2;
			violet.green = (int)((float)violet.green * possession) / 2;
			violet.blue = (int)((float)violet.blue * possession) / 2;
			violet.RGB = violet.red << 16 | violet.green << 8 | violet.blue;
			(*screen)[where_to + x] = violet.RGB; 
		}
		where_to += X_SIZE;
	}
}

void	display_pieces(t_filler gs, t_sqrt **board, int **screen)
{
	int		y;
	int		x;
	int		where_to;
	int 	tmp;
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
#include <signal.h>
#include "../includes/filler.h"

/*
void (*signal(int sig, void(*func)(int)))(int)
{

}
*/

void	sig_handler(int i)
{
	printf("%d\n", i);
}

int  main()
{
	for (int i = 1; i <= 31 ; i++)
	{
		signal(i, sig_handler);
	}
	while (1)
	{
	}
}
