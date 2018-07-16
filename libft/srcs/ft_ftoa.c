/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:30:29 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 15:50:21 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "../includes/libft.h"
#include <stdio.h>

char			*ft_ftoa(double nbr)
{
//	char			*str;
	int				size;
//	unsigned int	tmp;
	int				sign;

	sign = 0;
	size = ft_double_size(nbr);
	printf("%d\n", size);
	/*
	tmp = nbr;
	if (nbr < 0 && size++)
	{
		tmp = -nbr;
		sign = 1;
	}
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	(tmp == 0) ? str[size] = '0' : str[size];
	while (tmp > 0)
	{
		str[size--] = tmp % 10 + '0';
		tmp /= 10;
	}
	str[size] = (sign == 1) ? '-' : str[size];
	return (str);
	*/
	return (NULL);
}
