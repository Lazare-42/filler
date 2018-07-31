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
#include <stdio.h>

int	fast_gnl(int fd, char (*line)[4096])
{
	 int						rd;
	static char					buf[4096];
	char						*n_index;

	buf[4095] = 0;
	n_index = 0;
	rd = 0;
	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(ft_strchr(buf, '\n')))
		if ((rd = read(fd, buf, 4095) == -1))
			return (-1);
	n_index = ft_strchrnul(buf, '\n');
	ft_memcpy(*line, buf, n_index - buf);
	(*line)[n_index - buf] = '\0';
	ft_memcpy(buf, n_index + 1, 4095 - ft_strlen(*line));
	return (rd > 0 || ft_strlen(*line) > 0);
}
/*
int main(int argc, char *argv[])
{
	char	line[4096];
	int		ret;
	int		fd = open(argv[1], O_RDONLY);

	while ((ret = fast_gnl(fd, &line)))
		printf("ret = %d - line = \'%s\'\n", ret, line);
	printf("ret = %d - line = \'%s\'\n", ret, line);
	close(fd);
	return (0);
}*/
