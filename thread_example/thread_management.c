/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:39:01 by lazrossi          #+#    #+#             */
/*   Updated: 2018/03/16 15:49:31 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <sys/sysctl.h>
#include <pthread.h>

int		set_get_screen_lines_per_thread(int core_number)
{
	static int lines_per_thread = 0;

	if (!core_number)
		return (lines_per_thread);
	else
		lines_per_thread = Y_SIZE / set_get_core_numbers();
	return (lines_per_thread);
}

int		set_get_core_numbers(void)
{
	static int		core_number = 0;
	static size_t	count_len = sizeof(core_number);

	if (!core_number)
		sysctlbyname("hw.logicalcpu", &core_number, &count_len, NULL, 0);
	return (core_number);
}

void	create_threads(void func(void*), void *arg)
{
	int				y;
	t_screen_line	*arg_size;
	pthread_t		threads[Y_SIZE];

	y = -1;
	arg_size = arg;
	while (++y < set_get_core_numbers())
	{
		if (pthread_create(&threads[y], NULL, (void*)func,
					&(arg_size[y * set_get_screen_lines_per_thread(0)])))
			ft_myexit("thread creation error");
	}
	y = -1;
	while (++y < set_get_core_numbers())
		pthread_join(threads[y], NULL);
}
