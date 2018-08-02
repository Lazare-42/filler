/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budhabrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:14:03 by lazrossi          #+#    #+#             */
/*   Updated: 2018/03/16 10:24:33 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <pthread.h>

static void				suite_operation(t_complx complx_nbr, double color,
		t_complx suite_nbr, t_screen_line *screen_line)
{
	double	where_x;
	double	where_y;
	double	half_focus;
	double	focus;
	int		screen_size;

	focus = set_get_focus(0);
	half_focus = focus / 2;
	screen_size = X_SIZE * Y_SIZE;
	while (++color <= set_get_iterations(0))
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return ;
		else
		{
			where_x = ((suite_nbr.i + half_focus) / (focus)) * X_SIZE;
			where_y = (suite_nbr.r + half_focus) / focus;
			where_y = (int)(where_y * Y_SIZE) * X_SIZE;
			if ((int)(where_x + where_y) > 0 && (int)(where_x + where_y)
					< X_SIZE * Y_SIZE)
				(*screen_line->screen)[(int)(where_x + where_y)] += 1;
		}
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
	}
}

static void				screen_line_func(void *arg)
{
	t_screen_line	*screen_line;
	double			x;
	int				color;
	int				y;

	y = 0;
	color = 0;
	screen_line = arg;
	while (y < set_get_screen_lines_per_thread(0))
	{
		x = -1;
		while (++x < X_SIZE)
		{
			suite_operation((screen_line[y]).complx_nbr, 0,
					screen_line[y].complx_nbr_suite, &(screen_line[y]));
			screen_line[y].complx_nbr.r += screen_line[y].increment_r;
		}
		y++;
	}
}

static t_screen_line	*create_screen_line(void)
{
	t_screen_line	*screen_line;

	screen_line = NULL;
	if (!(screen_line = malloc(sizeof(t_screen_line) * Y_SIZE)))
		ft_myexit("malloc error");
	return (screen_line);
}

void					budhabrot(int **screen, t_complx complx_nbr_suite)
{
	int						y;
	double					increment_r;
	double					increment_i;
	static t_screen_line	*screen_line = NULL;
	double					increment_i_increment;

	increment_r = (double)(set_get_focus(0) / (double)X_SIZE);
	increment_i = (double)(set_get_focus(0) / (double)Y_SIZE);
	increment_i_increment = increment_i;
	y = -1;
	if (screen_line == NULL)
		screen_line = create_screen_line();
	while (++y < Y_SIZE)
	{
		screen_line[y].complx_nbr_suite = complx_nbr_suite;
		screen_line[y].y = y;
		screen_line[y].screen = screen;
		screen_line[y].increment_r = increment_r;
		increment_i += increment_i_increment;
		screen_line[y].complx_nbr.i = (set_get_focus(0) / 2)
			- increment_i - set_get_mouse_pos_at_zoom(0).i;
		screen_line[y].complx_nbr.r = -(set_get_focus(0) / 2)
			- set_get_mouse_pos_at_zoom(0).r;
	}
	create_threads(screen_line_func, screen_line);
}
