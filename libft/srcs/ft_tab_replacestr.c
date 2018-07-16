/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_replacestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 11:43:16 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/21 11:38:55 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_tab_replacestr(char ***tab, char **to_replace, char *cmp)
{
	int i;

	i = 0;
	while (*tab && (*tab)[i] && ft_memcmp((*tab)[i], cmp, ft_strlen(cmp)))
		i++;
	if (*tab && (*tab)[i])
	{
		ft_memdel((void**)&((*tab)[i]));
		if (!((*tab)[i] = ft_strdup(*to_replace)))
			return (NULL);
		ft_memdel((void**)to_replace);
		return (*tab);
	}
	else
	{
		if (!((*tab) = ft_tabdup_add_free(tab, to_replace, 'B')))
			return (NULL);
	}
	return (*tab);
}
