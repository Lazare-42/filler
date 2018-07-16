/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:30:47 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/18 15:30:51 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(char *str, char c)
{
	int i;
	int wn;
	int b;

	i = 0;
	wn = 0;
	b = 1;
	if (!*str)
		return (0);
	while (str[i])
	{
		if (b == 0 && (str[i] == c))
			b = 1;
		else if (b == 1 && str[i] != c)
		{
			wn++;
			b = 0;
		}
		i++;
	}
	return (wn);
}

static int		count_letters(char *str, int i, char c)
{
	int n;

	n = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		n++;
	}
	return (n);
}

static char		**create_tab(char **tab, char *str, char c)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			if (!(tab[k] = (char*)(malloc(sizeof(**tab) \
				* (count_letters(str, i, c) + 1)))))
				return (NULL);
			j = 0;
			while (str[i] && str[i] != c)
				tab[k][j++] = str[i++];
			tab[k++][j] = '\0';
		}
	}
	tab[k] = NULL;
	return (tab);
}

char			**ft_split_char(char *str, char c)
{
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(str, c) + 1))))
		return (NULL);
	tab = create_tab(tab, str, c);
	return (tab);
}
