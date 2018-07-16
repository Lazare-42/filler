/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:41:26 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/21 17:41:27 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	if (s && f)
	{
		if (!(ret = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		ret[ft_strlen(s)] = '\0';
		while (s[i])
		{
			ret[i] = f(s[i]);
			i++;
		}
		return (ret);
	}
	return (NULL);
}
