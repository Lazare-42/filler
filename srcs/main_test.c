/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/05 18:32:45 by lazrossi         ###   ########.fr       */
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
	t_arg			info;
	t_thread_arg	block[CORE_NUMBER];
	t_point			best_position;
	t_filler		game_settings;
	int				i;

	info.board = NULL;
	info.pc.layout = NULL;
	game_settings = get_game_settings();
	info.gs = &game_settings;
	i = -1;
	if (!(info.board = board_malloc(*(info.gs))))
		return (1);
	while (++i < CORE_NUMBER)
	{
		block[i].index = 0;
		if (!(block[i].board_cpy = board_malloc(*(info.gs))))
			return (1);
		block[i].info = info;
	}
	while (!info.gs->game_over)
	{
		pass_void_info();
		info.board = board_init(info.board, *(info.gs));
		get_piece(&info.pc);
		board_update(info.board, info.gs);
		i = -1;
		while (++i < CORE_NUMBER)
		{
			block[i].info.pc = info.pc;
			block[i].info.board = info.board;
		}
		best_position = get_best_position(block);
		ft_printf("%d %d\n", best_position.y - info.pc.free_lines, best_position.x - info.pc.free_columns);
	}
	return (0);
}
