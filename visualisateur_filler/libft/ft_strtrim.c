/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:53:54 by jboursal          #+#    #+#             */
/*   Updated: 2018/06/19 18:32:06 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strwsplenb(char const *s)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] && ft_isblank_or_n(s[i]))
		i++;
	while (len - j >= 0 && ft_isblank_or_n(s[len - j - 1]))
		j++;
	len = len - i - j + 1;
	if (len > 0)
		return (len);
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	len = strwsplenb(s);
	if (!(str = ft_strnew(sizeof(char) * (len - 1))))
		return (0);
	while (s[i] && ft_isblank_or_n(s[i]))
		i++;
	ft_strncpy(str, &(s[i]), len - 1);
	str[len] = 0;
	return (str);
}
