/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:32:30 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 16:21:36 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strstr_whilestr(char *haystack, char *needle, char *go)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0' || !ft_strchr(go, needle[j]))
		return (NULL);
	while (haystack[i] && ft_strchr(go, haystack[i]))
	{
		j = 0;
		while (needle[j] && ft_strchr(go, needle[j])
				&& needle[j] != haystack[i])
			j++;
		if (needle[j] && haystack[i] == needle[j])
			return (&(haystack[i]));
		i++;
	}
	return (NULL);
}
