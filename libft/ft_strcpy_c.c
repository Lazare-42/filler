/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:03:03 by jboursal          #+#    #+#             */
/*   Updated: 2018/04/19 23:08:18 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcpy_c(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}
