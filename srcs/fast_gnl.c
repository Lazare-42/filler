/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 05:58:11 by jboursal          #+#    #+#             */
/*   Updated: 2018/08/05 23:10:33 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/filler.h"

int			fast_gnl(const int fd, char (*line)[4096])
{
	int				rd;
	char			buf[BUFF_GNL + 1];
	static	char	s[BUFF_GNL * 4];
	char			*tmp;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	rd = 1;
	while (!(ft_strchr(s, '\n')))
	{
		rd = read(fd, buf, BUFF_GNL);
		buf[rd] = 0;
		tmp = ft_strchr(s, '\0');
		ft_memcpy(tmp, buf, ft_strlen(buf));
	}
	ft_memset(*line, '\0', BUFF_GNL);
	ft_memcpy(*line, s, ft_strchr(s, '\n') - s);
	ft_memcpy(s, ft_strchr(s, '\n') + 1, ft_strlen(s));
	return ((rd > 0) || (ft_strlen(*line) > 0));
}
