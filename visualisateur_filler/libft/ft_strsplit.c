/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:56:54 by jboursal          #+#    #+#             */
/*   Updated: 2018/07/12 20:15:35 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy_cb(char *dest, char *src, char c)
{
	int i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

static int	ft_strcountbb(char const *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (n);
}

static char	*ft_str_split_ptrb(char const *s, char c, int index)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (n == index)
				return ((char *)(&(s[i])));
			n++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str_tab;

	if (!s)
		return (0);
	if (!(str_tab = (char**)malloc(sizeof(char*) * ft_strcountbb(s, c) + 1)))
		return (0);
	i = 0;
	while (i < ft_strcountbb(s, c))
	{
		if (!(str_tab[i] = ft_strnew(sizeof(char) * ft_strlen(s))))
			return (0);
		ft_strcpy_cb(str_tab[i], ft_str_split_ptrb(s, c, i), c);
		i++;
	}
	str_tab[i] = NULL;
	return (str_tab);
}
