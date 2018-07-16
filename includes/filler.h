/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/17 00:24:10 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
#define FILLER_H

#include <stdlib.h>

typedef enum		e_direction
{up, right, down, left
}					t_direction;

typedef struct		s_sqrt
{
	int				boundary;
	float			possession;
}					t_sqrt;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_filler
{
	int				x_max;
	int				y_max;
	char			opponent;
}					t_filler;

t_sqrt	**board_malloc(t_filler game_settings);
t_sqrt	**board_init(t_sqrt **board, t_filler game_settings);
void	print_board(int x_max, int y_max, t_sqrt **board);
void	boundary_draw(t_sqrt **board, t_filler filler);

# endif
