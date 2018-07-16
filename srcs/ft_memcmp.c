/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:10:37 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 09:28:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1_cpy;
	const unsigned char *s2_cpy;

	s1_cpy = s1;
	s2_cpy = s2;
	while (n > 0 && *s1_cpy == *s2_cpy)
	{
		n--;
		s1_cpy++;
		s2_cpy++;
	}
	if (n != 0)
		return (*s1_cpy - *s2_cpy);
	else
		return (0);
}
