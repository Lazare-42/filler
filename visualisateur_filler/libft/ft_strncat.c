/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 20:40:12 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/03 23:35:09 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	index;
	unsigned int	index2;

	index = 0;
	index2 = 0;
	while (dest[index] != 0)
	{
		index++;
	}
	while (src[index2] != 0 && index2 < n)
	{
		dest[index + index2] = src[index2];
		index2++;
	}
	dest[index + index2] = 0;
	return (dest);
}
