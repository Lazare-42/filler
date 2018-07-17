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
