/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:10:48 by jboursal          #+#    #+#             */
/*   Updated: 2018/06/18 21:35:22 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nu_len(uintmax_t n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_utoa(uintmax_t n)
{
	int		i;
	int		len;
	char	*res;

	len = ft_nu_len(n);
	if (!(res = ft_strnew(sizeof(char) * len)))
		return (0);
	i = len - 1;
	while ((n / 10))
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	res[i] = n % 10 + '0';
	return (res);
}
