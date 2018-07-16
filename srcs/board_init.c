/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/16 20:25:48 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/includes/libft.h"

t_sqrt	**board_malloc(int x_max, int y_max)
{
	int		y;
	int		x;
	t_sqrt	**board;

	board = NULL;
	if (!(board = (t_sqrt **)malloc(sizeof(t_sqrt *) * y_max)))
		return (0);
	y = 0;
	while (y < y_max)
	{
		if (!(board[y] = (t_sqrt *)malloc(sizeof(t_sqrt) * x_max)))
			return (0);
		x = 0;
		while (x < x_max)
		{
			board[y][x].boundary = 0;
			board[y][x].possession = 0.5;
			x++;
		}
		y++;
	}
	return (board);
}

t_sqrt **board_init(t_sqrt **board, int x_max, int y_max)
{
	char	*buf;
	int		tmp;
	int		i;
	int		j;

	get_next_line(1, &buf, '\n');
	i = 0;
	while (i < y_max)
	{
		j = 0;
		while (!ft_strchr(".XO", *buf))
			buf++;
		while (j < x_max)
		{
			if (*buf == 'X')
				board[i][j].possession = 1;
			else if (*buf == 'O')
				board[i][j].possession = 0;
			buf++;
			j++;
		}
		i++;
		get_next_line(1, &buf, '\n');
	}
}

t_sqrt	**return_board(void)
{
	char	*buf;
	int		x;
	int		y;

	buf = NULL;
	get_next_line(1, &buf, '\n');
	while (!(ft_strstr(buf, "Plateau")))
		get_next_line(1, &buf, '\n');
	while (*buf && !(ft_isdigit(*buf)))
		buf++;
	y = ft_atoi(buf);
	while (*buf && (ft_isdigit(*buf)))
		buf++;
	x = ft_atoi(buf);
	return (board_init(board_malloc(x, y), x, y));
}
