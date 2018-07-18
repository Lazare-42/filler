/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/18 14:15:38 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
#define FILLER_H

# include <stdlib.h>
# include "../libft/libft.h"

# define FDF_P1 -2000000
# define FDF_P2 2000000

typedef enum		e_direction
{up, right, down, left
}					t_direction;

typedef struct		s_sqrt
{
	int				boundary;
	float			possession;
}					t_sqrt;

typedef struct		s_filler
{
	int				x_max;
	int				y_max;
	char			opponent;
}					t_filler;

typedef struct		s_piece
{
	int				**piece_layout;
	int				x_max;
	int				y_max;
}					t_piece;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_sqrt				**board_malloc(t_filler game_settings);
t_sqrt				**board_init(t_sqrt **board, t_filler game_settings);
void				print_board(int x_max, int y_max, t_sqrt **board);
void				boundary_draw(t_sqrt **board, t_filler filler);
t_filler			get_game_settings(void);
float				calc_score(t_sqrt **board, t_filler f);
void				print_piece(t_piece piece);
t_piece				get_piece(t_piece piece);

# endif
