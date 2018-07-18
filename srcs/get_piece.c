/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:02:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/18 14:15:38 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	**norm_piece(t_piece piece)
{
	int recurs;
	int	i;

	recurs  = 1;
	i = 0;
	while (piece && *piece)
	{
		if (**piece == 1)
			recurs = 0;
		piece++;
	}
}

t_piece	get_piece(t_piece piece)
{
	char	*buf;
	int		y_size;
	int		i;
	int		j;

	y_size = 0;
	i = 0;
	get_next_line(0, &buf);
	piece.y_max = ft_atoi(&buf[5]);
	get_next_line(0, &buf);
	piece.x_max = ft_strlen(buf);

	if (piece.piece_layout)
		ft_tabdel((void***)&piece.piece_layout);
	if (!(piece.piece_layout = malloc(sizeof(int *) * y_size + 1)))
		return (piece);
	piece.piece_layout[y_size] = NULL;
	while (i < y_size)
	{
		get_next_line(0, &buf);
		if (!(piece.piece_layout[i] = malloc(sizeof(int) * ft_strlen(buf))))
			return (piece);
		j = -1;
		while (++j < piece.x_max)
			piece.piece_layout[i][j] = (buf[j] == '*');
		i++;
	}
	return (piece);
}

void	print_piece(int **piece)
{
	int i;
	int j;
	
	int fd = open("./coucou", O_RDWR | O_CREAT | O_APPEND);
	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j] != -1)
		{
			ft_putnbr_fd(piece[i][j], fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
}
