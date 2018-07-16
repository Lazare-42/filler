/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:05:17 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:17:19 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** s in ft_s_base_converter stands for signed
*/

char	*operation(intmax_t number, int base_size, char *result, char minus)
{
	static char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";

	(number == 0) ? result[0] = '0' : 0;
	while (number)
	{
		if (!(result = ft_strjoinfree_char_str((
							base_output[number % base_size]), &result)))
			break ;
		number /= base_size;
		if (minus && !(number))
			result = ft_strjoinfree_char_str(minus, &result);
	}
	return (result);
}

char	*ft_s_base_converter(int base_size, intmax_t number)
{
	char		*result;
	char		minus;

	result = NULL;
	minus = 0;
	if (number < 0)
	{
		number *= -1;
		minus = '-';
	}
	if (base_size > 36)
		ft_putstr_fd("maximum base in ft_base_converter is 36\n", 2);
	else if (!(result = ft_strnew(1)))
		ft_putstr_fd("malloc error in ft_base_converter", 2);
	return (operation(number, base_size, result, minus));
}
