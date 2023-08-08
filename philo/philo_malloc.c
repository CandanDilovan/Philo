/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:42:50 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/13 14:29:24 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_malloc_again(t_all *philos, int a)
{
	philos->philo[a] = malloc(sizeof(t_iphilo));
	if (!(philos->philo[a]))
		return ;
	philos->philo[a]->timers = malloc(sizeof(t_timers));
	philos->philo[a]->thread = malloc(sizeof(pthread_t));
	philos->philo[a]->l_fork = malloc(sizeof(pthread_mutex_t));
	if (!(philos->philo[a]->thread || philos->philo[a]->r_fork
			|| philos->philo[a]->l_fork || philos->philo[a]->timers))
		return ;
	philos->philo[a]->noidea = &philos->lockeda;
	pthread_mutex_init(&philos->philo[a]->big_l, NULL);
	philos->philo[a]->lolcked = &philos->locked;
}

t_all	*philo_malloc(char **argv)
{
	t_all	*philos;
	int		a;

	a = -1;
	philos = malloc(sizeof(t_all));
	if (!(philos))
		return (NULL);
	pthread_mutex_init(&philos->lockeda, NULL);
	philos->philo = malloc(sizeof(t_iphilo *) * philo_atoi(argv[1]));
	pthread_mutex_init(&philos->locked, NULL);
	if (!(philos->philo))
		return (NULL);
	while (a < philo_atoi(argv[1]))
	{
		philo_malloc_again(philos, a);
		a++;
	}
	return (philos);
}

void	philo_alloc(int argc, char **argv, t_all **philos)
{
	int	a;

	a = -1;
	while ((*philos)->n_philo > ++a)
	{
		if (argc == 6)
			(*philos)->philo[a]->timers->miam_count = philo_atoi(argv[5]);
		else
			(*philos)->philo[a]->timers->miam_count = -1;
		(*philos)->philo[a]->timers->nb_philo = (*philos)->n_philo;
		(*philos)->philo[a]->timers->sl_t = philo_atoi(argv[4]);
		(*philos)->philo[a]->timers->e_t = philo_atoi(argv[3]);
		(*philos)->philo[a]->timers->s_t = ft_time();
		(*philos)->philo[a]->timers->d_t = philo_atoi(argv[2]);
		(*philos)->philo[a]->who = a;
		(*philos)->philo[a]->miam = 0;
		(*philos)->philo[a]->live = &(*philos)->alive;
		(*philos)->philo[a]->timers->t_miam = &(*philos)->done;
		pthread_mutex_init((*philos)->philo[a]->l_fork, NULL);
		if (a > 0)
			(*philos)->philo[a]->r_fork = (*philos)->philo[a - 1]->l_fork;
	}
	(*philos)->philo[0]->r_fork = (*philos)->philo[a - 1]->l_fork;
}
