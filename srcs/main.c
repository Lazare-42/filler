/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:48:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/05 21:05:36 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static float	**mask_init(void)
{
	int	y;
	int	x;
	float	**ret;
	float	model[16][16] = 
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	y = 0;
	ret = (float **)malloc(sizeof(float *) * 16);
	while (y < 16)
	{
		ret[y] = (float *)malloc(sizeof(float) * 16);
		x = 0;
		while (x < 16)
		{
			ret[y][x] = model[y][x];
			printf("%.f ", ret[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (ret);
}

void	pass_void_info(void)
{
	static	int first = 1;
	char		buf[BUFF_GNL];

	if (!first)
		fast_gnl(0, &buf);
	first = 0;
	fast_gnl(0, &buf);
}

void	main_loop_func(t_thread_arg block[CORE_NUMBER], t_arg info)
{
	t_point			best_position;
	int				i;

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
		ft_printf("%d %d\n", best_position.y - info.pc.free_lines,
		best_position.x - info.pc.free_columns);
	}
}

int		main(void)
{
	t_arg			info;
	t_thread_arg	block[CORE_NUMBER];
	t_filler		game_settings;
	int				i;

	info.board = NULL;
	info.pc.layout = NULL;
	game_settings = get_game_settings();
	game_settings.mask = mask_init();
	info.gs = &game_settings;
	i = -1;
	if (!(info.board = board_malloc(*(info.gs))))
		ft_myexit("malloc error");
	while (++i < CORE_NUMBER)
	{
		block[i].index = i;
		if (!(block[i].board_cpy = board_malloc(*(info.gs))))
			ft_myexit("malloc error");
		block[i].info = info;
	}
	main_loop_func(block, info);
	return (1);
}
