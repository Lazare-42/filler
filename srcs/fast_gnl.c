/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:58:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/26 09:14:35 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/filler.h"
#include <stdio.h>

int	fast_gnl(int fd, char (*line)[4096])
{
	static char					buf[BUFF_GNL];
	int							i;
	int							rd;

	rd = 0;
	i = 0;
	if (!(ft_strchr(buf, '\n')))
		if ((rd = read(fd, buf, BUFF_GNL - 1) == -1))
			return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	ft_memcpy((*line), buf, i);
	if (buf[i] && i == 0 && buf[i] == '\n')
		(*line)[2] = 0;
	else
		(*line)[i] = 0;
	ft_memcpy(buf, buf + i + 1, BUFF_GNL - i - 1);
	return (ft_strlen(*line));
}

/*

int main(int argc, char **argv)
{
	char	*line;
	char	buf[4096];
	int		ret;
	int		fd = open("/Users/lazrossi/Documents/42/filler/Makefile", O_RDONLY);

	(void)argv;
	ret = 1;
	if (argc == 2)
	{
		while ((ret))
		{
			ret = fast_gnl(fd, &buf);
			printf("%s\n", buf);
		}
		printf("%s\n", "we were in fast_gnl");
	}
	else 
	{
		while ((ret))
		{
			ret = get_next_line(fd, &line);
			printf("%s\n", line);
		}
	}
	close(fd);
	return (0);
}
*/
