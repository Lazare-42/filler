/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:01:51 by jboursal          #+#    #+#             */
/*   Updated: 2018/04/20 02:36:21 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_str_split_ptr(char const *s, char c, int index)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (n == index)
				return ((char *)(&(s[i])));
			n++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (0);
}
