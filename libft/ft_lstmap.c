/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:22:17 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/11 15:17:46 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_tmp;

	if (!lst || !f)
		return (0);
	if (!(new_list = f(lst)))
		return (0);
	new_tmp = new_list;
	while (lst->next && (new_tmp->next = f(lst->next)))
	{
		new_tmp = new_tmp->next;
		lst = lst->next;
	}
	new_tmp->next = NULL;
	return (new_list);
}
