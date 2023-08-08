/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:03 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/13 14:19:31 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(t_iphilo *p1, char *str, int what)
{
	uint64_t	time;

	pthread_mutex_lock(p1->lolcked);
	time = ft_time() - p1->timers->s_t;
	pthread_mutex_lock(p1->noidea);
	if (what == 0 && *p1->live == 1)
	{
		*p1->live = 0;
		printf("%llu Philo %d %s\n", time, p1->who, str);
	}
	if (*p1->live == 1)
	{
		printf("%llu Philo %d %s\n", time, p1->who, str);
	}
	pthread_mutex_unlock(p1->noidea);
	pthread_mutex_unlock(p1->lolcked);
}

static void	ft_sleeping(t_iphilo **p1)
{
	pthread_mutex_unlock((*p1)->l_fork);
	pthread_mutex_unlock((*p1)->r_fork);
	ft_message(*p1, "is sleeping", 1);
	ft_sleep((*p1)->timers->sl_t);
}

static void	ft_fork(t_iphilo **p1)
{
	if ((*p1)->who % 2 == 0)
	{
		pthread_mutex_lock((*p1)->l_fork);
		ft_message(*p1, "has taken a fork", 1);
		pthread_mutex_lock((*p1)->r_fork);
		ft_message(*p1, "has taken a fork", 1);
	}
	else
	{
		pthread_mutex_lock((*p1)->r_fork);
		ft_message(*p1, "has taken a fork", 1);
		pthread_mutex_lock((*p1)->l_fork);
		ft_message(*p1, "has taken a fork", 1);
	}
}

void	ft_eating(t_iphilo **p1)
{
	ft_fork(p1);
	pthread_mutex_lock(&(*p1)->big_l);
	(*p1)->miam = 1;
	(*p1)->timers->u_die = (*p1)->timers->d_t + ft_time();
	pthread_mutex_unlock(&(*p1)->big_l);
	ft_message(*p1, "is eating", 1);
	ft_sleep((*p1)->timers->e_t);
	pthread_mutex_lock(&(*p1)->big_l);
	(*p1)->miam = 0;
	pthread_mutex_unlock(&(*p1)->big_l);
	pthread_mutex_lock((*p1)->noidea);
	(*p1)->count++;
	pthread_mutex_unlock((*p1)->noidea);
	ft_sleeping(p1);
}
