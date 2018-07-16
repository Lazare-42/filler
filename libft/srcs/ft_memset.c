/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:00:17 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 14:00:39 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	str = s;
	i = 0;
	while (n > 0)
	{
		str[i] = (unsigned char)c;
		n--;
		i++;
	}
	return (s);
}
