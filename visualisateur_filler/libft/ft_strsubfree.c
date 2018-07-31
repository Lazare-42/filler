/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:12:14 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/03 19:56:23 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char **s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	if (!(str = ft_strnew(len)))
	{
		return (0);
	}
	while (i < len)
	{
		str[i] = (*s)[i + start];
		i++;
	}
	free(*s);
	return (str);
}
