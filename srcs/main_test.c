/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:02:34 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/26 08:37:37 by jboursal         ###   ########.fr       */
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

void	pass_void(void)
{
	static	int first = 1;
	char	buf[BUFF_SIZE];

	if (!first)
	{
		fast_gnl(0, &buf);
		usleep(500);
	}
	first = 0;
	fast_gnl(0, &buf);
}

int	main(void)
{
	t_sqrt		**board;
	t_sqrt		**board_cpy;
	t_filler	game_settings;
	t_point		best_position;
	t_piece		piece;

	board = NULL;
	piece.layout = NULL;
	game_settings = get_game_settings();
	if (!(board = board_malloc(game_settings)))
		return (1);
	if (!(board_cpy = board_malloc(game_settings)))
		return (1);
	while (1)
	{
		pass_void();
		board = board_init(board, game_settings);
		get_piece(&piece);
		board_update(board, &game_settings);
		best_position = get_best_position(board, &board_cpy, piece, &game_settings);
		printf("%d %d\n", best_position.y, best_position.x); fflush(stdout);
	}
	return (0);
}
