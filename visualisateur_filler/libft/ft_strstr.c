/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 20:53:49 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/09 20:01:31 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i])
	{
		while (big[i + j] && little[j] && big[i + j] == little[j])
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
