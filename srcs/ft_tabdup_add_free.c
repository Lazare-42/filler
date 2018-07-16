/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup_add_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:58:52 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/21 10:39:13 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	**ft_tabdup_add_free(char ***tab, char **str, char tofree)
{
	int		i;
	int		size;
	char	**new_tab;

	i = 0;
	new_tab = NULL;
	size = ft_tabsize(*tab) + 2;
	if (!(new_tab = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	new_tab[size - 1] = NULL;
	while (*tab && (*tab)[i])
	{
		if (!(new_tab[i] = ft_strdup((*tab)[i])))
			return (NULL);
		i++;
	}
	if (!(new_tab[i] = ft_strdup(*str)))
		return (NULL);
	if (*tab && (tofree == 'L' || tofree == 'B'))
		ft_tabdel((void***)tab);
	if (*str && (tofree == 'R' || tofree == 'B'))
		ft_memdel((void**)str);
	return (new_tab);
}
