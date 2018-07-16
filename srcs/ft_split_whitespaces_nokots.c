/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 09:49:14 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/18 15:30:18 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./../includes/libft.h"

static int		count_words(char *str)
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
		i = ft_advance_str_for_quotes(str, i);
		if (str[i] && b == 0 && (str[i] == ' '
					|| str[i] == '\n' || str[i] == '\t'))
			b = 1;
		else if (str[i] && b == 1 &&
				str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			wn++;
			b = 0;
		}
		i++;
	}
	return (wn);
}

static int		count_letters(char *str, int i)
{
	int n;

	n = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		i++;
		n++;
	}
	return (n);
}

static char		**create_tab(char **tab, char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\"')
		{
			if (!(tab[k] = (char*)(malloc(sizeof(**tab) \
				* (count_letters(str, i) + 1)))))
				return (NULL);
			j = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				tab[k][j++] = str[i++];
			tab[k++][j] = '\0';
		}
		else if (str[i])
			tab[k++] = ft_make_blocks_for_quotes(str, &i);
	}
	tab[k] = NULL;
	return (tab);
}

char			**ft_split_whitespaces_nokots(char *str)
{
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(str) + 1))))
		return (NULL);
	tab = create_tab(tab, str);
	return (tab);
}
