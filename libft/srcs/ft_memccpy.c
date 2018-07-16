/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:56:05 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 09:28:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;
	int					i;

	dest_cpy = dest;
	src_cpy = src;
	i = 0;
	while (n > 0)
	{
		dest_cpy[i] = src_cpy[i];
		if (src_cpy[i] == (unsigned char)c)
			return (&dest_cpy[++i]);
		i++;
		n--;
	}
	return (NULL);
}
