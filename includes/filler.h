/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/16 19:23:10 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
#define FILLER_H

#include <stdlib.h>

typedef struct		s_filler
{
	int				boundary;
	float			possession;
}					t_sqrt;

t_sqrt	**board_init(int x_max, int y_max);
void	print_board(int x_max, int y_max, t_sqrt **board);
void	get_possession(int x, int y);

# endif
