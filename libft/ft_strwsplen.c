/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwsplen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:53:54 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/08 16:24:48 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strwsplen(char const *s)
{
	int	ib;
	int	ie;
	int	len;

	ib = 0;
	ie = 0;
	len = ft_strlen(s) - 1;
	while (s[ib] && s[ib] == ' ')
		ib++;
	while (s[len - ie] == ' ')
		ie++;
	return (len - ib - ie + 1);
}
