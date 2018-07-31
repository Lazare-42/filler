/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:09:10 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/04 20:05:31 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	str = ft_strnew(sizeof(char) * ft_strlen(s));
	while (str && s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
