/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:10:48 by jboursal          #+#    #+#             */
/*   Updated: 2018/06/18 21:24:24 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(intmax_t n)
{
	int			i;
	int			len;
	char		*res;
	long long	long_n;

	len = ft_n_len(n) + (n < 0);
	if (!(res = ft_strnew(sizeof(char) * len)))
		return (0);
	i = len - 1;
	long_n = ft_abs((long long)n);
	while ((long_n / 10))
	{
		res[i] = long_n % 10 + '0';
		long_n /= 10;
		i--;
	}
	res[i] = long_n % 10 + '0';
	res[0] = (n < 0) ? '-' : res[0];
	return (res);
}
