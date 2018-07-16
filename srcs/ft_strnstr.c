/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:03:34 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 14:31:04 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;
	size_t cmp;

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
			while (haystack[cmp] == needle[j] && haystack[cmp] && needle[j] && \
					cmp < n)
			{
				if (haystack[cmp] == needle[j] && needle[j + 1] == '\0')
					return ((char*)haystack + i);
				j++;
				cmp++;
			}
		}
	}
	return (NULL);
}
