/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 20:34:09 by jboursal          #+#    #+#             */
/*   Updated: 2018/04/20 02:23:26 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	index;
	unsigned int	index2;

	index = 0;
	index2 = 0;
	while (dest[index] != 0)
	{
		index++;
	}
	while (src[index2] != 0)
	{
		dest[index + index2] = src[index2];
		index2++;
	}
	dest[index + index2] = 0;
	return (dest);
}
