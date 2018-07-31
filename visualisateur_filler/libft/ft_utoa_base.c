/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:10:48 by jboursal          #+#    #+#             */
/*   Updated: 2018/06/18 21:34:39 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len_base(uintmax_t n, const int base_len)
{
	size_t	i;

	i = 1;
	while (n /= base_len)
		i++;
	return (i);
}

char		*ft_utoa_base(uintmax_t n, const char *base)
{
	int		i;
	int		len;
	char	*res;
	int		base_len;

	if (!base)
		return (0);
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	len = ft_n_len_base(n, base_len);
	if (!(res = ft_strnew(sizeof(char) * len)))
		return (0);
	i = len - 1;
	while ((n / base_len))
	{
		res[i] = base[(n % base_len)];
		n /= base_len;
		i--;
	}
	res[i] = base[(n % base_len)];
	return (res);
}
