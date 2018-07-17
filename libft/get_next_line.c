/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 23:42:14 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/12 17:18:55 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line_len(const int fd, char **line)
{
	int	ret;

	ret = get_next_line(fd, line);
	if (ret == -1)
		return (-2);
	if (ret == 0)
		return (-1);
	return ((int)ft_strlen(*line));
}

int			grep_next_line(const int fd, char **line, const char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (get_next_line(fd, line) && !(ret = ft_strstr(*line, src)))
		i++;
	return ((ret > 0) * i);
}

int			get_next_line(const int fd, char **line)
{
	int			rd;
	char		buf[BUFF_SIZE + 1];
	static char	*s[OPEN_MAX];
	char		*tmp;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	ft_memset(buf, '\0', BUFF_SIZE);
	rd = 1;
	if (!S && !(S = ft_strnew(0)))
		return (-1);
	if (!(ft_strchr(S, SPLITC)))
		while (!ft_strchr(buf, SPLITC) && (rd = read(fd, buf, BUFF_SIZE)))
		{
			buf[rd] = 0;
			tmp = S;
			S = ft_strjoin(S, buf);
			free(tmp);
		}
	*line = ft_strsub(S, 0, ft_strchrnul(S, SPLITC) - S);
	tmp = S;
	S = ft_strchrnul(tmp, SPLITC);
	S = ft_strsub(tmp, S - tmp + 1, ft_strlen(S));
	free(tmp);
	return ((rd > 0) || (ft_strlen(*line) > 0));
}
