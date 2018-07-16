/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup_and_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:02:18 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/27 11:04:24 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	**ft_tabdup_and_add(char **tab, char *str)
{
	int		i;
	int		size;
	char	**new_tab;

	i = 0;
	new_tab = NULL;
	size = ft_tabsize(tab) + 2;
	if (!(new_tab = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	new_tab[size - 1] = NULL;
	while (tab && tab[i])
	{
		if (!(new_tab[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	if (!(new_tab[i] = ft_strdup(str)))
		return (NULL);
	return (new_tab);
}
