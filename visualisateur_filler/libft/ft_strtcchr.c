/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtcchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:11:33 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/05 20:50:16 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtcchr(const char *src, const char *tab, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] && src[i] != c)
	{
		j = 0;
		while (tab[j])
		{
			if (src[i] == tab[j])
			{
				return (&(((char*)src)[i]));
			}
			j++;
		}
		i++;
	}
	return (0);
}
