/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:21:47 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 09:28:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *first;

	if (!lst)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	new = f(new);
	first = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp = ft_lstnew(lst->content, lst->content_size);
		tmp = f(tmp);
		new->next = tmp;
		new = new->next;
	}
	return (first);
}
