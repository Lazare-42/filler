/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:01:32 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 10:26:59 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H


# include <unistd.h>

int					get_next_line(const int fd, char **line, char tofind);
typedef	struct		s_gnl
{
	char			*rest;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;
#endif
