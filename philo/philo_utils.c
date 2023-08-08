/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:45:33 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/02 18:16:57 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	ft_time(void)
{
	struct timeval	actualtime;

	if (gettimeofday(&actualtime, NULL) != 0)
		return (0);
	return ((actualtime.tv_sec * 1000) + (actualtime.tv_usec / 1000));
}

void	ft_sleep(u_int64_t time)
{
	uint64_t	start;

	start = ft_time();
	while (ft_time() < (time + start))
		usleep(100);
	return ;
}

int	philo_atoi(char *str)
{
	int	a;
	int	num;

	a = 0;
	num = 0;
	while (str[a] >= '0' && str[a] <= '9')
	{
		num = num * 10 + (str[a] - 48);
		a++;
	}
	return (num);
}
