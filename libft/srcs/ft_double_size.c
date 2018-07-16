/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:17:43 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:17:45 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_double_size(double nbr)
{
	int size;

	size = 1;
	while ((double)(nbr - (int)nbr))
	{
		printf("%f\n", (double)(nbr - (int)nbr));
		nbr = (double)((double)nbr * (double)10);
		debug();
	}
	while (nbr / 10)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}
