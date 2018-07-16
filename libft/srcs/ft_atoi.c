/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:29:19 by lazrossi          #+#    #+#             */
/*   Updated: 2017/04/19 15:19:51 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int number;

	number = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f' || \
			nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = nptr[i] - 48 + number * 10;
		i++;
	}
	return (number * sign);
}
