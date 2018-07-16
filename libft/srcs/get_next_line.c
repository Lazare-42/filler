/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:30:36 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/27 14:12:53 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char	*ft_str_join_free(char **s1, char **s2)
{
	char *str;

	str = ft_strjoin(*s1, *s2);
	ft_memdel((void*)s1);
	return (str);
}

int		ft_fillup(char **line, t_gnl **stock, char tofind)
{
	*line = NULL;
	if ((*stock)->rest && ft_strchr((*stock)->rest, tofind))
	{
		*line = ft_strnew((ft_strchr((*stock)->rest, tofind) - (*stock)->rest));
		*line = ft_strncpy(*line, (*stock)->rest, \
				((ft_strchr((*stock)->rest, tofind) - (*stock)->rest)));
		(*stock)->rest = ft_strcpy((*stock)->rest,
				ft_strchr((*stock)->rest, tofind) + 1);
		return (1);
	}
	else if ((*stock)->rest && *(*stock)->rest)
	{
		*line = ft_strnew(ft_strlen((*stock)->rest));
		*line = ft_strdup((*stock)->rest);
		(*stock)->rest = NULL;
		return (1);
	}
	return (0);
}

t_gnl	*manage_stock(t_gnl **stock, int fd)
{
	t_gnl *tmp;
	t_gnl *new;

	new = NULL;
	if (*stock)
	{
		tmp = *stock;
		while (tmp->next && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp->fd == fd)
			return (tmp);
	}
	if (!(new = ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	new->rest = ft_strnew(0);
	new->fd = fd;
	if (*stock)
	{
		new->next = *stock;
		*stock = new;
		return (new);
	}
	new->next = NULL;
	*stock = new;
	return (*stock);
}

int		get_next_line(const int fd, char **line, char tofind)
{
	static t_gnl	*stock = NULL;
	t_gnl			*tmp;
	char			*buf;
	int				ret;

	buf = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if (!(tmp = manage_stock(&stock, fd)))
		return (-1);
	ret = 1;
	while ((ft_strchr(buf, tofind) == NULL))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
		{
			ft_strdel(&(buf));
			return (ft_fillup(line, &tmp, tofind));
		}
		buf[ret] = '\0';
		tmp->rest = ft_str_join_free(&tmp->rest, &buf);
	}
	ft_strdel(&(buf));
	return (ft_fillup(line, &tmp, tofind));
}
