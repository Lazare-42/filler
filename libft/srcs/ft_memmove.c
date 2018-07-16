/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:16:35 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 09:28:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *dest_cpy;
	char *src_cpy;

	src_cpy = (char*)src;
	dest_cpy = (char*)dest;
	if (src_cpy > dest_cpy)
	{
		while (n > 0)
		{
			*dest_cpy++ = *src_cpy++;
			n--;
		}
	}
	else
		while (n > 0)
		{
			dest_cpy = dest_cpy + n - 1;
			src_cpy = src_cpy + n - 1;
			while (n > 0)
			{
				*dest_cpy-- = *src_cpy--;
				n--;
			}
		}
	return (dest);
}
