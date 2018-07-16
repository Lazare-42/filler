/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:02:24 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 14:02:42 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == c)
		return ((char*)&s[i]);
	while (s[i])
	{
		i++;
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (NULL);
}
