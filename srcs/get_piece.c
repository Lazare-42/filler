/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:02:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/18 19:20:37 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

int	check_empty_column(t_piece piece)
{
	int free_columns;
	int	i;

	free_columns = 0;
	while (free_columns < piece.x_max - 1)
	{
		i = -1;
		while (++i < piece.y_max)
			if (piece.piece_layout[i][free_columns] == 1)
				return (free_columns);
		free_columns++;
	}
	return (free_columns);
}

void	swap_columns(t_piece piece, int free_columns)
{
	int i;
	int j;

	i = 0;
		while (i < piece.y_max)
		{
			j = 0;
			while (j + free_columns < piece.x_max)
			{
				piece.piece_layout[i][j] =
				piece.piece_layout[i][j + free_columns];
				piece.piece_layout[i][j + free_columns] =
				(j + free_columns * 2  < piece.x_max) ?
				piece.piece_layout[i][j + free_columns * 2] : 0;
				j++;
			}
			i++;
		}
}

int check_empty_line(t_piece piece)
{
	int free_lines;
	int i;

	free_lines = 0;
	while (free_lines < piece.y_max)
	{
		i = -1;
		while (++i < piece.x_max)
			if (piece.piece_layout[free_lines][i] == 1)
				return (free_lines);
		free_lines++;
	}
	return (free_lines);
}

void	swap_lines(t_piece piece, int free_lines)
{
	int i;
	int j;
	
	i = 0;
	while (i < piece.x_max)
	{
		j = 0;
		while (j + free_lines < piece.y_max)
		{
			piece.piece_layout[j][i] =
			piece.piece_layout[j + free_lines][i];
			piece.piece_layout[j + free_lines][i] =
			(j + free_lines * 2  < piece.y_max) ? 
			piece.piece_layout[j + free_lines * 2][i] : 0;
			j++;
		}
		i++;
	}
}

t_piece norm_piece(t_piece piece)
{
	int	free_columns;
	int free_lines;

	free_columns = 0;
	free_lines = 0;
	if ((free_columns = check_empty_column(piece)))
		swap_columns(piece, free_columns);
	if ((free_lines = check_empty_line(piece)))
		swap_lines(piece, free_lines);
	print_piece(piece);
	piece.x_max -= free_columns;
	piece.y_max -= free_lines;
	return (piece);
}

void	print_piece(t_piece piece)
{
	int i;
	int j;

	int fd = open("./coucou", O_RDWR | O_CREAT | O_APPEND);
	ft_putstr_fd("\nthis is piece.y_max : ", fd);
	ft_putnbr_fd(piece.y_max, fd);
	ft_putstr_fd("\nthis is piece.x_max : ", fd);
	ft_putnbr_fd(piece.x_max, fd);
	ft_putstr_fd("\n", fd);
	i = 0;
	while (i < piece.y_max)
	{
		j = 0;
		while (j < piece.x_max)
		{
			ft_putnbr_fd(piece.piece_layout[i][j], fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
	close(fd);
}
