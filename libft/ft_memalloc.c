/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:31:25 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/23 18:08:33 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	if (!(mem = malloc(size)))
		return (0);
	i = 0;
	while (i < size && mem != 0)
	{
		((char*)mem)[i] = 0;
		i++;
	}
	return (mem);
}
