/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:58:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/01 21:50:31 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/filler.h"
#include <stdio.h>
/*
int	fast_gnl(int fd, char (*line)[4096])
{
	static char				buf[BUFF_GNL];
	int						i;
	int						rd;

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
*/

int			fast_gnl(const int fd, char (*line)[4096])
{
	int				rd;
	char			buf[BUFF_GNL + 1];
	static	char	s[BUFF_GNL * 4];
	static	int		is_already_init;
	char			*tmp;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	ft_memset(buf, '\0', BUFF_GNL + 1);
	rd = 1;
	if (!(is_already_init++))
		ft_memset(s, '\0', BUFF_GNL * 4);
	if (!(ft_strchr(s, '\n')))
	{
		rd = read(fd, buf, BUFF_GNL);
		buf[rd] = 0;
		tmp = ft_strchr(s, '\0');
		ft_memcpy(tmp, buf, ft_strlen(buf));
	}
	ft_memset(*line, '\0', BUFF_GNL + 1);
	ft_memcpy(*line, s, ft_strchrnul(s, '\n') - s);
	ft_memcpy(s, ft_strchrnul(s, '\n') + 1, ft_strlen(s));
	return ((rd > 0) || (ft_strlen(*line) > 0));
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	int		rd;
	char	line[BUFF_GNL + 1];
	char	*line2;
	int		fd = open(argv[1], O_RDONLY);

	while ((rd = fast_gnl_2(fd, &line)))
	{
		printf("rd = %d - line = \'%s\'\n", rd, line); fflush(stdout);
	}
	printf("rd = %d - line = \'%s\'\n", rd, line); fflush(stdout);
	close(fd);
	return (0);
}*/
