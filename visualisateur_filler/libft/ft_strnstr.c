/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 21:10:21 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/09 20:01:47 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i] && i < len - 1)
	{
		while (big[i + j] && little[j] && big[i + j] == little[j]
		&& i + j < len)
			j++;
		if (little[j] == 0)
			break ;
		i++;
		j = 0;
	}
	if (big[i + j] == little[j] || little[j] == 0)
		return (&(((char*)big)[i]));
	return (NULL);
}
