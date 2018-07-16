/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fatal_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:37:35 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/21 11:37:37 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

int		ft_put_fatal_error(char *str)
{
	ft_putstr_fd("Exiting for the following reason : ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
