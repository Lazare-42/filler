/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advance_for_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:59:22 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/18 14:01:50 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int		ft_advance_str_for_quotes(char *str, int i)
{
	if (str[i] && str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
	}
	return (i);
}

char	*ft_strdup_to_quote(char *src, char *dst)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	i = ft_advance_str_for_quotes(src, i);
	if (!(dst = (char*)(malloc(sizeof(char) * i))))
		return (NULL);
	dst[i - 1] = '\0';
	i = 1;
	while (src[i] && src[i] != '\"')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	return (dst);
}

char	*ft_make_blocks_for_quotes(char *str, int *i)
{
	char *new_string;

	new_string = NULL;
	if (str[*i] && str[1 + *i] && str[*i] == '\"' && str[1 + *i] == '\"')
		*i = *i + 2;
	(str[*i] == '\"') ?
		new_string = ft_strdup_to_quote(&str[*i], new_string) : 0;
	*i = (str[*i] == '\"') ? ft_advance_str_for_quotes(str, *i) : *i;
	(*i)++;
	return (new_string);
}
