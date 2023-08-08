/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:19:55 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/13 14:41:42 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_all **philos)
{
	int	a;

	a = -1;
	while (++a != (*philos)->n_philo)
	{
		free((*philos)->philo[a]->timers);
		free((*philos)->philo[a]->thread);
		pthread_mutex_destroy((*philos)->philo[a]->l_fork);
		free((*philos)->philo[a]->l_fork);
		free((*philos)->philo[a]);
	}
	free((*philos)->philo);
	pthread_mutex_destroy(&(*philos)->locked);
	pthread_mutex_destroy(&(*philos)->lockeda);
	free(*philos);
}
