/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/06 03:40:00 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"

# define P1 1
# define P2 0
# define BUFF_GNL 4096
# define SET_MEMO 20000
# define CORE_NUMBER 8
# define FILL_MODE 5000
# define VAR 1
# define PERIMETRE 150
# define OPTI 0

typedef struct		s_sqrt
{
	float			possession;
	float			p1_distance;
	float			p2_distance;
}					t_sqrt;

typedef struct		s_filler
{
	int				x_max;
	int				y_max;
	int				opponent;
	float			**mask;
	int				fill_mode;
	int				game_over;
}					t_filler;

typedef struct		s_piece
{
	int				**layout;
	int				x_max;
	int				y_max;
	int				free_lines;
	int				free_columns;
}					t_piece;

typedef struct		s_fpoint
{
	float			x;
	float			y;
}					t_fpoint;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_memo
{
	t_point			memo;
	float			score;
}					t_memo;

typedef struct		s_arg
{
	t_sqrt			**board;
	t_filler		*gs;
	t_piece			pc;
	t_memo			memo;
}					t_arg;

typedef struct		s_thread_arg
{
	t_sqrt			**board_cpy;
	t_memo			memo;
	t_arg			info;
	int				index;
}					t_thread_arg;

t_sqrt				**board_malloc(t_filler game_settings);
t_sqrt				**board_init(t_sqrt **board, t_filler game_setting);
void				print_board(int x_max, int y_max, t_sqrt **board);
void				boundary_draw(t_sqrt **board, t_filler filler);
t_filler			get_game_settings(void);
float				calc_score(t_sqrt **board, t_filler f);
void				print_piece_before_norm(t_piece piece);
void				print_piece_after_norm(t_piece piece);
void				get_piece(t_piece *piece);
void				norm_piece(t_piece *piece);
void				print_board_old(int x_max, int y_max, t_sqrt **board);
t_point				get_best_position(t_thread_arg block[CORE_NUMBER]);
void				board_update(t_sqrt **board, t_filler *gs);
void				board_print(t_sqrt **board, t_filler gs);
void				board_distance_update_1(t_sqrt **board, t_filler gs);
void				board_distance_update_2(t_sqrt **board, t_filler gs);
void				board_distance_update_3(t_sqrt **board, t_filler gs);
void				board_distance_update_4(t_sqrt **board, t_filler gs);
void				board_distance_update_5(t_sqrt **board, t_filler gs);
void				board_distance_update_6(t_sqrt **board, t_filler gs);
void				board_distance_update_7(t_sqrt **board, t_filler gs);
void				board_distance_update_8(t_sqrt **board, t_filler gs);
void				find_winner(t_filler *game_settings, char *buf);
int					fast_gnl(const int fd, char (*line)[4096]);
void				board_possession_update(t_sqrt **board, t_filler *gs);
float				score_update(t_sqrt ***board_cpy, float *high_score,
		t_filler *gs);
t_point				get_best_score_from_tab(t_thread_arg block[CORE_NUMBER]);
t_point				t_point_init(int x, int y);
t_point				get_best_position_fill(t_sqrt **board, t_piece pc,
		t_filler *gs);
t_point				get_best_position_fill_and_win(t_sqrt **board, t_piece pc,
		t_filler *gs);
int					is_placeable(t_sqrt **board, t_piece pc, t_point o,
		t_filler gs);
t_point				t_point_init(int x, int y);
void				board_to_board(t_sqrt **src, t_sqrt ***dest, t_filler gs);

#endif
