/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:24:49 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/25 09:46:03 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*stock_next;

	stock_next = *alst;
	if (alst == NULL || *alst == NULL)
		return ;
	if (del != NULL)
	{
		while (stock_next->next != NULL)
		{
			*alst = stock_next;
			stock_next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free((*alst));
			*alst = NULL;
		}
		*alst = stock_next;
		del((*alst)->content, (*alst)->content_size);
		free((*alst));
		*alst = NULL;
	}
}
