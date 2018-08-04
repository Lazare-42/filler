/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_pieces_or_find_winner.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 00:39:00 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/04 00:59:16 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	find_winner(t_filler *game_settings, char buf[BUFF_GNL])
{
	int				p1_score;
	int				p2_score;
	char			tmp[BUFF_GNL];

	p1_score = ft_atoi(&buf[9]);
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
	}
	fast_gnl(0, &buf);
	if (ft_strstr(buf, "fin"))
		find_winner(game_settings, buf);
}
