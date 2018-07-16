/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:22:51 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:29:54 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*print_bits(void *ptr, int size)
{
	int		i;
	int		bit_nbr;
	char	*result;
	char	*test;
	int		j;

	i = 7;
	j = 0;
	bit_nbr = 0;
	test = ptr;
	if (!(result = ft_strnew(size * 10)))
		return (NULL);
	while (j < size)
	{
		result[bit_nbr] = (test[j] & (1 << i)) ? '1' : '0';
		bit_nbr++;
		(i == 4) ? result[bit_nbr] = ' ' : 0;
		(i == 4) ? bit_nbr++ : 0;
		(i == 0) ? result[bit_nbr] = ' ' : 0;
		(i == 0) ? j++ : 0;
		(i == 0) ? bit_nbr++ : 0;
		(i == 0) ? i = 8 : 0;
		i--;
	}
	return (result);
}
