/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:37:29 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/09 19:54:21 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if ((const void*)dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		i = 1;
		while (i <= n)
		{
			((char*)dest)[n - i] = ((char*)src)[n - i];
			i++;
		}
	}
	return (dest);
}
