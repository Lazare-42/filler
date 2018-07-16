/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:16:39 by lazrossi          #+#    #+#             */
/*   Updated: 2017/05/12 13:48:06 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char **s1, char **s2, char a)
{
	char *str;

	str = ft_strjoin(*s1, *s2);
	if (a == 'L')
		ft_memdel((void*)s1);
	if (a == 'R')
		ft_memdel((void*)s2);
	if (a == 'B')
	{
		ft_memdel((void*)s1);
		ft_memdel((void*)s2);
	}
	return (str);
}
