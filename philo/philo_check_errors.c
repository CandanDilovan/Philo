/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:06:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/06/05 15:45:25 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argv(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] < '0' || str[a] > '9')
			return (1);
		a++;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int	a;

	a = 1;
	while (argc > a)
	{
		if (check_argv(argv[a]) == 1)
			return (1);
		if (philo_atoi(argv[a]) < 0)
			return (1);
		if (philo_atoi(argv[a]) > 2147483647)
			return (1);
		a++;
	}
	return (0);
}
