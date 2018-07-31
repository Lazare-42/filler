/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:10:48 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/25 00:17:57 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len_base(unsigned long n, const int base_len)
{
	unsigned long	i;

	i = 1;
	while (n /= base_len)
		i++;
	return (i);
}

char		*ft_get_add(const void *p)
{
	char			*base;
	char			*res;
	int				i;
	int				len;
	unsigned long	adr;

	base = ft_strdup("0123456789abcdef");
	adr = (unsigned long)p;
	len = ft_n_len_base(adr, 16);
	if (!(res = ft_strnew(len)))
		return (0);
	i = len - 1;
	while ((adr / 16))
	{
		res[i] = base[adr % 16];
		adr /= 16;
		i--;
	}
	res[i] = base[adr % 16];
	free(base);
	base = res;
	res = ft_strjoin("0x", res);
	free(base);
	return (res);
}
