/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nn_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:13:04 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/05 20:48:59 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nn_strjoin(char const *s1, char const *s2, size_t l1, size_t l2)
{
	char	*str;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = ft_strnew(sizeof(char) * (l1 + l2))))
		return (0);
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i2 < l2)
	{
		str[i + i2] = s2[i2];
		i2++;
	}
	str[i + i2] = 0;
	return (str);
}
