/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 11:18:32 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/28 16:32:16 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoinfree_one(char **s1, char *s2, char where)
{
	char *str;

	if (where == 'B')
	{
		if (!(str = ft_strjoin(s2, *s1)))
			return (NULL);
	}
	else if (!(str = ft_strjoin(*s1, s2)))
		return (NULL);
	ft_memdel((void*)s1);
	return (str);
}
