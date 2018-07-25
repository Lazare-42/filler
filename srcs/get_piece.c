/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:02:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/25 22:21:27 by lazrossi         ###   ########.fr       */
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
			if (piece.layout[i][free_columns] == 1)
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
				piece.layout[i][j] =
				piece.layout[i][j + free_columns];
				piece.layout[i][j + free_columns] =
				(j + free_columns * 2  < piece.x_max) ?
				piece.layout[i][j + free_columns * 2] : 0;
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
			if (piece.layout[free_lines][i] == 1)
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
			piece.layout[j][i] =
			piece.layout[j + free_lines][i];
			piece.layout[j + free_lines][i] =
			(j + free_lines * 2  < piece.y_max) ? 
			piece.layout[j + free_lines * 2][i] : 0;
			j++;
		}
		i++;
	}
}

t_piece norm_piece(t_piece piece)
{
	if ((piece.free_columns = check_empty_column(piece)))
		swap_columns(piece, piece.free_columns);
	if ((piece.free_lines = check_empty_line(piece)))
		swap_lines(piece, piece.free_lines);
	piece.x_max -= piece.free_columns;
	piece.y_max -= piece.free_lines;
	return (piece);
}

void	print_piece(t_piece piece)
{
	int i;
	int j;

//	ft_printf("[[~/Documents/42/filler/debug.txt]]\nDEBUG");
	ft_printf("[[~/Documents/42/filler/piece.txt]]\nthis is piece.y_max : %d\nthis is piece.x_max : %d\n", piece.y_max, piece.x_max);
	i = 0;
	while (i < piece.y_max)
	{
		j = 0;
		while (j < piece.x_max)
		{
			ft_printf("[[~/Documents/42/filler/piece.txt]]%d", piece.layout[i][j]);
			j++;
		}
			ft_printf("[[~/Documents/42/filler/piece.txt]]\n");
		i++;
	}
	ft_printf("[[~/Documents/42/filler/piece.txt]]\n");
}
