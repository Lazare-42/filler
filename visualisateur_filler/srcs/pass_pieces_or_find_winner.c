/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_pieces_or_find_winner.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:11:03 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/04 13:11:04 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	find_winner(t_filler *game_settings, char *buf)
{
	int				p1_score;
	int				p2_score;

	p1_score = ft_atoi(&buf[9]);
	ft_memdel((void**)&buf);
	get_next_line(0, &buf);
	p2_score = ft_atoi(&buf[9]);
	ft_memdel((void**)&buf);
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
	char			*buf;

	while (get_next_line(0, &buf) && !(ft_strstr(buf, "Plateau")))
	{
		if (ft_strstr(buf, "fin"))
			find_winner(game_settings, buf);
		else
			ft_memdel((void**)&buf);
	}
	ft_memdel((void**)&buf);
	get_next_line(0, &buf);
	if (ft_strstr(buf, "fin"))
		find_winner(game_settings, buf);
	else
		ft_memdel((void**)&buf);
}
