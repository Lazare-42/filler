/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:02:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/05 23:12:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

int		check_empty_column_before(t_piece piece)
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

int		check_empty_line_before(t_piece piece)
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

int		check_empty_line_after(t_piece piece)
{
	int	free_lines;
	int	empty_line;
	int	i;

	free_lines = piece.free_lines;
	empty_line = 0;
	while (free_lines < piece.y_max && !empty_line)
	{
		empty_line = 1;
		i = (piece.free_columns) ? piece.free_columns : 0;
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

int		check_empty_columns_after(t_piece piece)
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
	piece->free_columns = check_empty_column_before(*piece);
	piece->free_lines = check_empty_line_before(*piece);
	piece->y_max = check_empty_line_after(*piece);
	piece->x_max = check_empty_columns_after(*piece);
}
