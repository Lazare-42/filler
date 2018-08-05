/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:02:34 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/05 06:18:30 by lazrossi         ###   ########.fr       */
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

void	pass_void_info(void)
{
	static	int first = 1;
	char	buf[BUFF_GNL];

	if (!first)
		fast_gnl(0, &buf);
	first = 0;
	fast_gnl(0, &buf);
}

int	main(void)
{
	t_arg		all[CORE_NUMBER];
	t_point		best_position;
	int			i;

	all[0].board = NULL;
	all[0].pc->layout = NULL;
	*(all[0].gs) = get_game_settings();
	i = 0;
	ft_printf("[[~/Documents/42/filler/test.txt]]COUCOU?\n");
	if (!(all[0].board = board_malloc(*(all[0].gs))))
		return (1);
	while (i < CORE_NUMBER)
	{
		if (!(all[i].board_cpy = board_malloc(*(all[0].gs))))
			return (1);
		all[i].board = all[0].board;
		all[i].gs = all[0].gs;
		i++;
	}
	while (!(all[0].gs->game_over))
	{
		pass_void_info();
		all[0].board = board_init(all[0].board, *(all[0].gs));
		get_piece(all[0].pc);
		i = -1;
		while (++i < CORE_NUMBER)
			all[i].pc = all[0].pc;
		board_update(all[0].board, all[0].gs);
		best_position = get_best_position(all);
		ft_printf("%d %d\n", best_position.y - all[0].pc->free_lines, best_position.x - all[0].pc->free_columns);
	}
	return (0);
}
