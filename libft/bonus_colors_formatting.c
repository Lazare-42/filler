/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_colors_formatting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:25:13 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:56:53 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		help(void)
{
	ft_printf("Available formatting options for \
[[yellow]][[underline]][[bold]][[italic]]lazrossi's fr_printf\
[[end]] are :\n [[red]]red,\n [[green]]green,\n [[yellow]]yellow[[end]],\
	\n [[blue]]blue,\n [[magenta]]magenta,\n [[cyan]]cyan,\n [[white]]white,\
	\n [[end]][[underline]]underline[[end]],\
	\n [[bold]]bold,\n [[end]][[italic]]italic,\n [[end]][[blink]]blink,\
	\n [[end]][[background]]setting [[underline]]background[[end]] color\
	\n [[swapp]][[underline]][[italic]]swapp[[end]][[swapp]]ing foreground");
	ft_printf("and background");
	ft_printf("colors.[[end]]\n Simply [[italic]]input[[end]] those options");
	ft_printf("in your ft_printf string in the following fashion :\
			\n[[end]] [[bold]][[option]]\
	\n[[red]][[bold]][[underline]]Caution :[[end]] some escape sequences may");
	ft_printf(" not be supported by your terminal.");
}

const char	*continue_font_formatting(const char *format, t_str *argument)
{
	if (!(ft_strncmp(format, "[[background]]", 14)))
	{
		update_str(argument, BCK, 5);
		format += 14;
	}
	else if (!(ft_strncmp(format, "[[underline]]", 13)))
	{
		update_str(argument, UND, 4);
		format += 13;
	}
	else if (!(ft_strncmp(format, "[[swapp]]", 9)))
	{
		update_str(argument, SWP, 4);
		format += 9;
	}
	else if (!(ft_strncmp(format, "[[help?]]", 9)))
	{
		help();
		return (NULL);
	}
	else
		return (format);
	return (terminal_formatting(format, argument));
}

const char	*font_formatting(const char *format, t_str *argument)
{
	if (!(ft_strncmp(format, "[[bold]]", 8)))
	{
		update_str(argument, BLD, 4);
		format += 8;
	}
	else if (!(ft_strncmp(format, "[[end]]", 7)))
	{
		update_str(argument, RESET, 4);
		format += 7;
	}
	else if (!(ft_strncmp(format, "[[italic]]", 10)))
	{
		update_str(argument, ITA, 4);
		format += 10;
	}
	else if (!(ft_strncmp(format, "[[blink]]", 9)))
	{
		update_str(argument, BLK, 4);
		format += 9;
	}
	else
		return (format = continue_font_formatting(format, argument));
	return (terminal_formatting(format, argument));
}

const char	*continue_color_formatting(const char *format, t_str *argument)
{
	if (!(ft_strncmp(format, "[[blue]]", 8)))
	{
		update_str(argument, BLU, 5);
		format += 8;
	}
	else if (!(ft_strncmp(format, "[[magenta]]", 11)))
	{
		update_str(argument, MAG, 5);
		format += 11;
	}
	else if (!(ft_strncmp(format, "[[cyan]]", 8)))
	{
		update_str(argument, CYN, 5);
		format += 8;
	}
	else if (!(ft_strncmp(format, "[[white]]", 9)))
	{
		update_str(argument, WHT, 5);
		format += 9;
	}
	else
		return (format = font_formatting(format, argument));
	return (terminal_formatting(format, argument));
}

const char	*terminal_formatting(const char *format, t_str *argument)
{
	if (argument->position + 5 >= BUFF_SIZE - 1)
		launch_string_print(NULL, 0, argument, 1);
	if (!(ft_strncmp(format, "[[~/", 4)) || !ft_strncmp(format, "[[fd=", 5)
			|| !ft_strncmp(format, "[[no_append", 11))
		format = choose_set_file_descriptor(format, argument);
	else if (!(ft_strncmp(format, "[[red]]", 7)))
	{
		update_str(argument, RED, 5);
		format += 7;
	}
	else if (!(ft_strncmp(format, "[[green]]", 9)))
	{
		update_str(argument, GRN, 5);
		format += 9;
	}
	else if (!(ft_strncmp(format, "[[yellow]]", 10)))
	{
		update_str(argument, YEL, 5);
		format += 10;
	}
	else
		return (format = continue_color_formatting(format, argument));
	return (terminal_formatting(format, argument));
}
