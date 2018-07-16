/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:22:31 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/20 09:54:58 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_cpy;
	const char	*src_cpy;
	size_t		n;
	size_t		len_fin;

	n = size;
	dst_cpy = dst;
	src_cpy = src;
	while (n-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	len_fin = dst_cpy - dst;
	n = size - len_fin;
	if (n == 0)
		return (len_fin + ft_strlen((char*)src_cpy));
	while (*src_cpy)
	{
		if (n != 1)
		{
			*dst_cpy++ = *src_cpy;
			n--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (len_fin + (src_cpy - src));
}
