/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:57:29 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 17:14:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char const	*src_byte;
	unsigned char		*dest_byte;

	i = 0;
	src_byte = src;
	dest_byte = dest;
	while (n > 0)
	{
		dest_byte[i] = src_byte[i];
		n--;
		i++;
	}
	return (dest);
}
