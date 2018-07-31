/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:10:48 by jboursal          #+#    #+#             */
/*   Updated: 2018/06/18 21:23:08 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len_base(long long n, const int base_len)
{
	unsigned long	i;

	i = 1;
	while (n /= base_len)
		i++;
	return (i);
}

char		*ft_itoa_base(intmax_t n, const char *base)
{
	int			i;
	int			len;
	char		*res;
	long long	long_n;
	int			base_len;

	if (!base)
		return (0);
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	len = ft_n_len_base(n, base_len) + (n < 0);
	if (!(res = ft_strnew(sizeof(char) * len)))
		return (0);
	i = len - 1;
	long_n = ft_abs((long long)n);
	while ((long_n / base_len))
	{
		res[i] = base[(long_n % base_len)];
		long_n /= base_len;
		i--;
	}
	res[i] = base[(long_n % base_len)];
	res[0] = (n < 0) ? '-' : res[0];
	return (res);
}
