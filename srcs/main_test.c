/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:02:34 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/05 01:45:21 by lazrossi         ###   ########.fr       */
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
	t_arg		all;
	t_point		best_position;
	int			i;

	all.board = NULL;
	all.pc.layout = NULL;
	all.gs = get_game_settings();
	i = 0;
	if (!(all.board = board_malloc(all.gs)))
		return (1);
	while (i < 4)
	{
		all.board_cpy[i] = board_malloc(all.gs);
		i++;
	}
	while (!all.gs.game_over)
	{
		pass_void_info();
		all.board = board_init(all.board, all.gs);
		get_piece(&all.pc);
		board_update(all.board, &all.gs);
		best_position = get_best_position(&all, &(all.gs));
		ft_printf("%d %d\n", best_position.y - all.pc.free_lines, best_position.x - all.pc.free_columns);
	}
	return (0);
}
