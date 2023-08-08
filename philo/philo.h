/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:42:01 by dilovancand       #+#    #+#             */
/*   Updated: 2023/07/24 11:29:52 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_timers
{
	uint64_t	d_t;
	uint64_t	sl_t;
	uint64_t	e_t;
	uint64_t	s_t;
	uint64_t	u_die;
	int			miam_count;
	int			nb_philo;
	int			*t_miam;
}				t_timers;

typedef struct s_iphilo
{
	int				who;
	int				miam;
	int				*live;
	int				count;
	t_timers		*timers;
	pthread_t		*thread;
	pthread_mutex_t	*noidea;
	pthread_mutex_t	big_l;
	pthread_mutex_t	*lolcked;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_iphilo;

typedef struct s_all
{
	t_iphilo		**philo;
	pthread_mutex_t	locked;
	pthread_mutex_t	lockeda;
	int				alive;
	int				done;
	int				n_philo;

}				t_all;

//malloc
t_all		*philo_malloc(char **argv);
void		philo_alloc(int argc, char **argv, t_all **philos);

//free
void		free_all(t_all **philos);

//utils
int			philo_atoi(char *str);
u_int64_t	ft_time(void);
void		ft_sleep(uint64_t time);

//actions
void		ft_eating(t_iphilo **p1);
void		ft_message(t_iphilo *p1, char *str, int what);

//death check
int			check_death(t_all *p1);
int			check_miam(t_all *p1);

//errors
int			check_errors(int argc, char **argv);

#endif