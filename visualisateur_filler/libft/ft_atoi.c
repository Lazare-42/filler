/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 21:25:24 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/24 19:11:06 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long	n;
	size_t		i;
	int			pos;

	n = 0;
	i = 0;
	pos = 1;
	while (ft_isspace(nptr[i]) && nptr[i] != '-' && nptr[i] != '+')
		i++;
	if (nptr[i] == '-')
		pos = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		n = n * 10 + nptr[i++] - '0';
	return ((int)(n * pos));
}
