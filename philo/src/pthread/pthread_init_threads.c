/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_init_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:01:09 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 06:35:41 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	detach_threads(t_threads *threads, size_t nb_philo,
	size_t nb_philos, size_t nb_medics)
{
	size_t			i;

	i = 0;
	while (i < nb_philos || i < nb_medics)
	{
		if (i < nb_philos)
			pthread_detach(threads->philos[i]);
		if (i < nb_medics)
			pthread_detach(threads->medics[i]);
		i++;
	}
	clear_mutex(threads, nb_philo);
	destroy_mutex_threads(threads);
}

int	init_threads(t_threads *threads, t_philo *args, size_t nb_philo)
{
	t_msec			time;
	size_t			i;

	time = ft_current_time();
	i = -1;
	while (++i < nb_philo)
	{
		args[i].begin_time = time;
		args[i].last_meal = time;
		if (pthread_create(threads->philos + i, NULL,
				philo_routine, args + i) != 0)
		{
			detach_threads(threads, nb_philo, i, i);
			return (-1);
		}
		args[i].philos = threads->philos[i];
		if (pthread_create(threads->medics + i, NULL,
				philo_death, args + i) != 0)
		{
			detach_threads(threads, nb_philo, i + 1, i);
			return (-1);
		}
	}
	return (0);
}
