/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree_stackstr_heapstr.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:20:37 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:20:45 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char				*ft_joinfree_heapstr_stackstr(char **s1, char *s2,
		char where)
{
	char *str;

	str = NULL;
	debug();
	ft_putstr(*s1);
	ft_putstr(s2);
	if (where == 'b')
		str = ft_strjoin(s2, *s1);
	else
		str = ft_strjoin(*s1, s2);
	if (*s1)
		ft_memdel((void*)s1);
	return (str);
}
