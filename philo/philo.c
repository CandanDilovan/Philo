/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:53:29 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/08 14:35:11 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_one_philo(t_all **philos)
{
	(*philos)->philo[0]->timers->s_t = ft_time();
	ft_message((*philos)->philo[0],"has taken a fork", 4);
	ft_sleep((*philos)->philo[0]->timers->d_t);
	ft_message((*philos)->philo[0], "is dead", 4);
	free_all(philos);
	return (0);
}

void	*dying(void *input)
{
	t_all	*p1;

	p1 = (t_all *)input;
	ft_sleep(1);
	while (1)
	{
		if (check_death(p1) == 1)
			break ;
		if (check_miam(p1) == 1)
			break ;
	}
	return (0);
}

static void	*ft_tuorp(void *input)
{	
	t_iphilo	*philo;

	philo = (t_iphilo *)input;
	pthread_mutex_lock(&philo->big_l);
	philo->timers->u_die = philo->timers->d_t + ft_time();
	pthread_mutex_unlock(&philo->big_l);
	while (1)
	{	
		ft_eating(&philo);
		ft_message(philo, "is thinking", 2);
		pthread_mutex_lock(philo->noidea);
		if (*philo->live == 0)
		{
			pthread_mutex_unlock(philo->noidea);
			break ;
		}
		else
			pthread_mutex_unlock(philo->noidea);
	}
	return (0);
}

static void	ft_philo(t_all **philos)
{
	int			a;
	pthread_t	watching;

	a = 0;
	while (a < (*philos)->n_philo)
	{
		pthread_create((*philos)->philo[a]->thread, NULL, &ft_tuorp,
			(void *)(*philos)->philo[a]);
		if (!(*philos)->philo[a]->thread)
			return ;
		a++;
	}
	pthread_create(&watching, NULL, &dying, *philos);
	a = 0;
	while (a < (*philos)->n_philo)
	{
		pthread_join(*(*philos)->philo[a]->thread, NULL);
		if (!(*philos)->philo[a]->thread)
			return ;
		a++;
	}
	pthread_join(watching, NULL);
}

int	main(int argc, char **argv)
{
	t_all			*philos;

	if (argc < 5 || argc > 6)
		return (write(2, "Error\n", 6));
	if (check_errors(argc, argv) == 1)
		return (write(2, "Error\n", 6));
	philos = philo_malloc(argv);
	philos->n_philo = philo_atoi(argv[1]);
	philos->alive = 1;
	philos->done = 0;
	philo_alloc(argc, argv, &philos);
	if (philos->n_philo == 1)
		return (ft_one_philo(&philos));
	else
		ft_philo(&philos);
	free_all(&philos);
	system("leaks philo");
	return (0);
}
