/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:25:10 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/05 20:49:57 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = ft_strnew(sizeof(char) * (ft_strlen(s1) + n))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (i2 < n)
	{
		str[i + i2] = s2[i2];
		i2++;
	}
	str[i + i2] = 0;
	return (str);
}
