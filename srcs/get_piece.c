/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:02:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/26 01:23:19 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

int	check_empty_column_before(t_piece piece)
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

int check_empty_line_before(t_piece piece)
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

int check_empty_line_after(t_piece piece)
{
	int	free_lines;	
	int	empty_line;
	int	i;

	free_lines = piece.free_lines;
	empty_line = 0;
	while (free_lines < piece.y_max && !empty_line)
	{
		empty_line = 1;
		i = (piece.free_columns) ? piece.free_columns: 0;
		while (i < piece.x_max)
		{
			if (piece.layout[free_lines][i] == 1)
				empty_line = 0;
			i++;
		}
		if (!empty_line)
			free_lines++;
	}
	return (free_lines - piece.free_lines);
}

int check_empty_columns_after(t_piece piece)
{
	int free_columns;
	int empty_column;
	int i;

	free_columns = piece.free_columns;
	empty_column = 0;
	while (free_columns < piece.x_max && !empty_column)
	{
		empty_column = 1;
		i = (piece.free_lines) ? piece.free_lines : 0;
		while (i < piece.y_max + piece.free_lines)
		{
			if (piece.layout[i][free_columns] == 1)
					empty_column = 0;
			i++;
		}
		if (!empty_column)
			free_columns++;
	}
	return (free_columns - piece.free_columns);
}

void	norm_piece(t_piece *piece)
{
//	print_piece_before_norm(*piece);
	piece->free_columns = check_empty_column_before(*piece);
	piece->free_lines = check_empty_line_before(*piece);
	piece->y_max = check_empty_line_after(*piece);
	piece->x_max = check_empty_columns_after(*piece);
//	print_piece_after_norm(*piece);
}

void	print_piece_before_norm(t_piece piece)
{
	int i;
	int j;

	ft_printf("[[~/Documents/42/filler/piece.txt]]\nBefore norm this is piece.y_max : %d\nthis is piece.x_max : %d\n", piece.y_max, piece.x_max);
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

void	print_piece_after_norm(t_piece piece)
{
	int i;
	int j;

	ft_printf("[[~/Documents/42/filler/piece.txt]]\n\
After norm this is piece.y_max : %d\nthis is piece.x_max : %d\nthis is free_lines %d\nthis\
 is free_columns %d\n", piece.y_max, piece.x_max, piece.free_lines, piece.free_columns);
	i = piece.free_lines;
	while (i < (piece.y_max + piece.free_lines))
	{
		j = piece.free_columns;
		while (j < (piece.x_max + piece.free_columns))
		{
			ft_printf("[[~/Documents/42/filler/piece.txt]]%d", piece.layout[i][j]);
			j++;
		}
			ft_printf("[[~/Documents/42/filler/piece.txt]]\n");
		i++;
	}
	ft_printf("[[~/Documents/42/filler/piece.txt]]\n");
}
