/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:46:56 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/18 14:07:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static char	*ft_str_alloccpy(char const *src, size_t size)
{
	char	*dst;

	if (!(dst = ft_strnew(size)))
		return (NULL);
	dst = ft_strncpy(dst, (char*)src, size);
	return (dst);
}

static char	**ft_count_tab(char const *s, char c)
{
	char	**new;
	size_t	b;
	size_t	count;

	b = 1;
	count = 0;
	while (*s)
	{
		while (*s == '\"')
			s++;
		if (b == 0 && *s == c)
			b = 1;
		else if (b == 1 && *s != c)
		{
			count++;
			b = 0;
		}
		s++;
	}
	if (!(new = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	new[count] = NULL;
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**new;
	char const	*s2;
	size_t		i;

	i = 0;
	if (!s || (!(new = ft_count_tab(s, c))))
		return (NULL);
	while (*s)
	{
		while (*s == '\"')
			s++;
		while (*s && *s == c)
			s++;
		s2 = s;
		while (*s2 && *s2 != c)
			s2++;
		s2--;
		if (*s)
		{
			if (!(new[i++] = ft_str_alloccpy(s, (s2 - s) + 1)))
				return (NULL);
			s = s2 + 1;
		}
	}
	return (new);
}
