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

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int cmp;

	i = -1;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[++i])
	{
		cmp = i;
		j = 0;
		if (haystack[cmp] == needle[j])
		{
			while (haystack[cmp] == needle[j] && haystack[cmp] && needle[j])
			{
				if (haystack[cmp] == needle[j] && (needle[j + 1] == '\0' \
						|| needle[j] == '\0'))
					return ((char*)haystack + i);
				cmp++;
				j++;
			}
		}
	}
	return (NULL);
}
