/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:31:23 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/16 15:59:23 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_m;

	if (!(new_m = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content)
	{
		if (!(new_m->content = malloc(content_size)))
			return (0);
		ft_memcpy(new_m->content, content, content_size);
		new_m->content_size = content_size;
	}
	else
	{
		new_m->content = NULL;
		new_m->content_size = 0;
	}
	new_m->next = NULL;
	return (new_m);
}
