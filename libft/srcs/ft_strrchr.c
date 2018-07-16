/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:31:45 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 14:31:57 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = i;
	if (s[i] == c)
		j = i;
	while (s[i])
	{
		i++;
		if (s[i] == c)
			j = i;
	}
	if (s[j] == c)
		return ((char*)&s[j]);
	return (NULL);
}
