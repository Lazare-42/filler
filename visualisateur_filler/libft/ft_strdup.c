/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 20:13:44 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/25 00:19:20 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*scpy;
	int				len;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	if (!(scpy = (char*)malloc(sizeof(char) * len)))
		return (0);
	return (ft_memcpy(scpy, s, len));
}
