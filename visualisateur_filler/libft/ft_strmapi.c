/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:20:24 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/04 20:20:53 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == 0)
		return (0);
	str = ft_strnew(sizeof(char) * ft_strlen(s));
	while (str && s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
