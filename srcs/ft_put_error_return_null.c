/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error_return_null.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:18:40 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:18:42 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_put_error_return_null(char *error_msg, char *function_name)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(" in function : ", 2);
	ft_putstr_fd(function_name, 2);
	ft_putchar('\n');
	return (NULL);
}
