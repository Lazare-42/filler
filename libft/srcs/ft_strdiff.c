/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:27:05 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:30:32 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdiff(char *str, char c, int size)
{
	int i;

	i = 0;
	while (str[i] && str[i] == c && size--)
		i++;
	if (!str[i] || !size)
		return (NULL);
	else
		return (&str[i]);
}
