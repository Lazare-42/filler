/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:02:34 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/05 03:28:33 by lazrossi         ###   ########.fr       */
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
	t_filler	game_settings;
	t_piece		piece;
	t_sqrt		**board;
	int			i;

	i = -1;
	game_settings = get_game_settings();
	if (!(board = board_malloc(game_settings)))
		ft_myexit("malloc error");
	piece.layout = NULL;
	board = NULL;
	while (++i < CORE_NUMBER)
	{
		all[i].gs = &game_settings;
		all[i].board = board;
		all[i].pc = &piece;
		if (!(all[i].board_cpy = board_malloc(game_settings)))
			ft_myexit("malloc error");
	}
	while (!game_settings.game_over)
	{
		pass_void_info();
		board = board_init(board, game_settings);
		get_piece(&piece);
		board_update(board, &game_settings);
		best_position = get_best_position(all);
		ft_printf("%d %d\n", best_position.y - piece.free_lines, best_position.x - piece.free_columns);
	}
	return (0);
}
