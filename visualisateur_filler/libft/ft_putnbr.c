/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:22:08 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/08 20:31:47 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar('-');
		long_n = ft_abs(long_n);
	}
	if (long_n > 9)
		ft_putnbr(long_n / 10);
	ft_putchar(long_n % 10 + '0');
}
