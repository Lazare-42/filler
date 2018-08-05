/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:23:14 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/05 17:36:51 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <wordexp.h>

int			set_get_fd(int action)
{
	static int fd = 1;

	if (!action)
		return (fd);
	else
		fd = action;
	return (action);
}

void		try_opening(void *path, int o_flag)
{
	char		*path_read;
	wordexp_t	path_exp;
	int			fd;

	path_read = (char*)path;
	fd = 0;
	if (wordexp(path_read, &path_exp, 0))
		ft_printf("path expansion error\n", path, strerror(errno));
	else if ((fd = open(*path_exp.we_wordv, o_flag, S_IRWXU)) < 0)
	{
		ft_printf("FD option : Error in opening creating the file : ");
		ft_printf("%s. Error :  %s\n", path, strerror(errno));
	}
	if (fd > 0)
		set_get_fd(fd);
}

const char	*continue_setting_fd(const char *format, int no_append)
{
	int		i;
	int		o_flag;
	char	path[2049];

	i = 0;
	ft_memset(path, 0, 2049);
	o_flag = O_RDWR | O_CREAT;
	o_flag |= (no_append) ? 0 : O_APPEND;
	if (!(ft_strncmp(format, "[[~/", 4)))
	{
		format += 2;
		while (*format && *format != ']')
		{
			ft_memcpy(path + i, format, 1);
			i++;
			format++;
		}
		format += 2;
		try_opening((void*)path, o_flag);
	}
	return (format);
}

const char	*choose_set_file_descriptor(const char *format, t_str *argument)
{
	int		no_append;
	int		fd;

	no_append = 0;
	launch_string_print(NULL, 0, argument, 1);
	if ((fd = set_get_fd(0)) != 1)
		close(fd);
	if (!(ft_strncmp(format, "[[fd=", 5)))
	{
		format += 5;
		set_get_fd(ft_atoi(format));
		while (*format && *format != ']')
			format++;
		if (*format && *format == ']')
			format++;
	}
	if (!ft_strncmp(format, "[[no_append]]", 13))
	{
		format += 13;
		no_append = 1;
	}
	return (continue_setting_fd(format, no_append));
}
