/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 00:20:27 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/21 15:58:11 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * n + 1)))
		return (0);
	str[n] = 0;
	while (src[i] && i <= n)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
