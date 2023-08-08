/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ded.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:27:13 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/24 11:29:09 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_all *p1)
{
	int	a;

	a = -1;
	while (++a != p1->n_philo)
	{
		pthread_mutex_lock(&p1->philo[a]->big_l);
		if (p1->philo[a]->timers->u_die < ft_time() && p1->philo[a]->miam == 0)
		{	
			ft_message(p1->philo[a], "is dead", 0);
			pthread_mutex_unlock(&p1->philo[a]->big_l);
			return (1);
		}
		else
			pthread_mutex_unlock(&p1->philo[a]->big_l);
	}
	return (0);
}

int	check_miam(t_all *p1)
{
	int	a;

	a = -1;
	while (++a != p1->n_philo)
	{
		pthread_mutex_lock(p1->philo[a]->noidea);
		if (p1->philo[a]->timers->miam_count == p1->philo[a]->count)
		{
			p1->done++;
			p1->philo[a]->count++;
			if (p1->philo[a]->timers->nb_philo == *p1->philo[a]->timers->t_miam)
			{
				*p1->philo[a]->live = 0;
				pthread_mutex_unlock(p1->philo[a]->noidea);
				return (1);
			}
			else
				pthread_mutex_unlock(p1->philo[a]->noidea);
		}
		else
			pthread_mutex_unlock(p1->philo[a]->noidea);
	}
	return (0);
}
