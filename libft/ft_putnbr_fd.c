/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:22:08 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/08 20:32:03 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n = ft_abs(long_n);
	}
	if (long_n > 9)
		ft_putnbr_fd(long_n / 10, fd);
	ft_putchar_fd(long_n % 10 + '0', fd);
}
