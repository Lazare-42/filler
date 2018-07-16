/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:10:27 by lazrossi          #+#    #+#             */
/*   Updated: 2017/09/05 09:28:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;

	tmp = lst;
	if (!lst)
		return ;
	while (tmp->next != NULL)
	{
		lst = tmp;
		tmp = lst->next;
		f(lst);
	}
	f(tmp);
}
