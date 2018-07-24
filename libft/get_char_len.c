/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:41:43 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/24 18:58:55 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			strlen_argument_wide_char(va_list ap)
{
	int		i;
	int		j;
	wchar_t	*str;

	j = 0;
	str = NULL;
	i = 0;
	str = va_arg(ap, wchar_t*);
	if (!str)
		return (ft_strlen("(null)"));
	while (str[j++])
	{
		if (str[j] < 128)
			i += 1;
		else if (str[j] < 2048)
			i += 2;
		else if (str[j] < 131071)
			i += 3;
		else
			i += 4;
	}
	return (i);
}

int			get_char_len(va_list ap, t_printf *argument)
{
	char	*c;

	c = NULL;
	if (argument->type == 's' && !*argument->modifier)
	{
		c = va_arg(ap, char *);
		if (c)
			return (ft_strlen(c));
		else
			return (ft_strlen("(null)"));
	}
	else if (ft_strchr("Cc", argument->type))
		return (1);
	if (argument->type == 'S'
			|| (argument->type == 's' && *argument->modifier == 'l'))
		return (strlen_argument_wide_char(ap));
	return (0);
}
