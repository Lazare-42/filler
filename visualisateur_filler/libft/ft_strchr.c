/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboursal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 20:45:40 by jboursal          #+#    #+#             */
/*   Updated: 2018/05/24 19:09:40 by jboursal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0 && s[i] != (unsigned char)c)
	{
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&(((char*)s)[i]));
	return (0);
}
