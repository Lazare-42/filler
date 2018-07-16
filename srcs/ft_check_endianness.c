/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_endianness.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:58:43 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:00:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** this function returns 1 if the machine is little-endian
*/

int	ft_check_endianness(void)
{
	unsigned int	x;
	char			*c;

	x = 1;
	c = NULL;
	c = (char*)&x;
	return ((int)*c);
}
