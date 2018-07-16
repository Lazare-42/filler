/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:19:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 18:28:39 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	double_it(const char *nptr, double number)
{
	double	behind;
	int		i;

	behind = 0.1;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number += (double)((double)(nptr[i] - 48) * (double)behind);
		behind = (double)((double)behind * (double)0.1);
		i++;
	}
	return (number);
}

double			ft_atof(const char *nptr)
{
	int		i;
	int		sign;
	double	number;

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
	if (nptr[i] == '.')
		number = double_it(&nptr[++i], number);
	return (((double)number * (double)sign));
}
