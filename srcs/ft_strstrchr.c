/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:32:30 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/25 12:24:32 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstrchr(char *haystack, char *needle, char stop)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0' || needle[j] == stop)
		return (NULL);
	while (haystack[i] && haystack[i] != stop)
	{
		j = 0;
		while (needle[j] && needle[j] != stop && needle[j] != haystack[i])
			j++;
		if (haystack[i] == needle[j])
			return (&(haystack[i]));
		i++;
	}
	return (NULL);
}
