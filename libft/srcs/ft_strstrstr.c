/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:32:30 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:31:38 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strstrstr(char *haystack, char *needle, char *stop)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0' || ft_strchr(stop, needle[j]))
		return (NULL);
	while (haystack[i] && !ft_strchr(stop, haystack[i]))
	{
		j = 0;
		while (needle[j] && !ft_strchr(stop, needle[j])
				&& needle[j] != haystack[i])
			j++;
		if (haystack[i] == needle[j])
			return (&(haystack[i]));
		i++;
	}
	return (NULL);
}
