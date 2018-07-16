/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:29:17 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/29 15:00:27 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putabs(char **str, char separator)
{
	int i;

	i = -1;
	while (str && str[++i])
	{
		ft_putstr(str[i]);
		ft_putchar(separator);
	}
}
