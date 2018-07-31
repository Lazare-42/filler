/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:10:50 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/05 20:49:28 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctchr(const char *src, char c, const char *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (&(((char*)src)[i]));
		j = 0;
		while (tab[j])
		{
			if (src[i] == tab[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
