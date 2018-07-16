/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:36:19 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/28 09:39:32 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

void	debug(void)
{
	static int nbr = 0;

	nbr++;
	ft_putstr("Debug");
	ft_putchar(' ');
	ft_putnbr(nbr);
	ft_putchar('\n');
}
