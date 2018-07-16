/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:03:33 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 09:28:50 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int s;

	s = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		s = -n;
	}
	else
		s = n;
	if (s / 10)
		ft_putnbr_fd(s / 10, fd);
	ft_putchar_fd((s % 10 + '0'), fd);
}
