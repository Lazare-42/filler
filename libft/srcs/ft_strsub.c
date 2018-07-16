/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:05:21 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/21 17:45:18 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;

	if (s)
	{
		if (!(substr = ft_strnew(len)))
			return (NULL);
		ft_strncpy(substr, (char*)&s[start], len);
		return (substr);
	}
	return (NULL);
}
