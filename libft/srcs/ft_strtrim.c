/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:08:13 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/21 17:46:11 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*trimmed;
	char const	*end;

	if (!s)
		return (NULL);
	end = (s + ft_strlen(s)) - 1;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (*end == ' ' || *end == '\t' || *end == '\n')
		end--;
	if (end < s)
	{
		if (!(trimmed = ft_strnew(0)))
			return (NULL);
	}
	else
	{
		if (!(trimmed = ft_strnew((end - s) + 1)))
			return (NULL);
		trimmed = ft_strncpy(trimmed, (char*)s, (end - s) + 1);
	}
	return (trimmed);
}
