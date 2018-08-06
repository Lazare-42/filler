/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 13:39:47 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include "../libft/libft.h"

# define P1 1
# define P2 0
# define BOARD 60
# define BUFF_GNL 4096
# define X_SIZE 1200
# define Y_SIZE 1200
# define VIOLET 0x9370DB
# define CYAN	0x37FDFC
# define GREY	0xA9A9A9
# define WIN_CO 0xee0000

typedef struct		s_sqrt
{
	float			possession;
	float			p1_distance;
	float			p2_distance;
}					t_sqrt;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
	int				keycode;
}					t_mlx;

typedef struct		s_filler
{
	int				x_max;
	int				y_max;
	int				player;
	float			p1_possession;
	float			p2_possession;
	char			p1_info[1024];
	char			p2_info[1024];
	int				game_over;
	int				end_score;
}					t_filler;

t_sqrt				**board_malloc(t_filler game_settings);
t_sqrt				**board_init(t_sqrt **board, t_filler *game_setting);
void				print_board(int x_max, int y_max, t_sqrt **board);
void				boundary_draw(t_sqrt **board, t_filler filler);
t_filler			get_game_settings(void);
float				calc_score(t_sqrt **board, t_filler f);
void				print_board_old(int x_max, int y_max, t_sqrt **board);
void				board_update(t_sqrt **board, t_filler *gs);
void				board_print(t_sqrt **board, t_filler gs);
void				board_img_handler(void);
int					draw(void);
void				board_distance_reset(t_sqrt **board, t_filler gs);
void				possession_update(t_sqrt **board, t_filler filler);
void				set_get_total_possession_p1(float possession, void *ret);
void				board_distance_update_1(t_sqrt **board, t_filler gs);
void				board_distance_update_2(t_sqrt **board, t_filler gs);
void				board_distance_update_3(t_sqrt **board, t_filler gs);
void				board_distance_update_4(t_sqrt **board, t_filler gs);
void				board_distance_update_5(t_sqrt **board, t_filler gs);
void				board_distance_update_6(t_sqrt **board, t_filler gs);
void				board_distance_update_7(t_sqrt **board, t_filler gs);
void				board_distance_update_8(t_sqrt **board, t_filler gs);
void				board_possession_update(t_sqrt **board, t_filler filler);
void				get_total_possession(t_sqrt **board, t_filler *gs);
void				display_pieces(t_filler game_settings, t_sqrt **board,
		int **screen);
void				put_player_info(t_mlx mlx, t_filler gs, int player);
void				pass_pieces_or_find_winner(t_filler *game_settings);
void				find_winner(t_filler *game_settings, char *buf);
int					loop_filler(int necessary);
t_mlx				my_mlx_init(void);

#endif
