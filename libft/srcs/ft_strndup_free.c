/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 00:20:27 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 13:08:10 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strndup_free(char **src, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strnew(n)))
		return (NULL);
	while (*src && (*src)[i] && i < n)
	{
		str[i] = (*src)[i];
		i++;
	}
	ft_memdel((void**)src);
	return (str);
}
