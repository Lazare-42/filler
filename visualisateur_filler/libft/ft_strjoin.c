/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:58:18 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 16:21:54 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*concat;

	concat = NULL;
	if (s1 || s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(concat = ft_strnew(len)))
			return (NULL);
		if (s1)
		{
			if (!(ft_strcpy((char*)concat, (char*)s1)))
				return (NULL);
		}
		if (s2)
		{
			if (!(ft_strcat(concat, (char*)s2)))
				return (NULL);
		}
		return (concat);
	}
	return (NULL);
}
