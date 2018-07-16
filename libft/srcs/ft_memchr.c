/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:47:00 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/21 17:34:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_cpy;

	s_cpy = (unsigned char*)s;
	while (n > 0 && *s_cpy != (unsigned char)c)
	{
		n--;
		s_cpy++;
	}
	if (n != 0)
		return (&*s_cpy);
	else
		return (NULL);
}
