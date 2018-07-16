/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree_str_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:18:54 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/28 16:31:43 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoinfree_char_str(char s2, char **s1)
{
	char	*str;
	int		len;

	str = NULL;
	len = 0;
	if (*s1 || s2)
	{
		len = ft_strlen(*s1) + 1;
		if (!(str = ft_strnew(len)))
			return (NULL);
		str[0] = s2;
		if (*s1)
		{
			if (!(ft_strcpy(&str[1], *s1)))
				return (NULL);
			ft_memdel((void*)s1);
		}
		return (str);
	}
	return (NULL);
}
