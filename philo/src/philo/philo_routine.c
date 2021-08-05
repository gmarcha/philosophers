/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:29:27 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 16:01:38 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	hehe(t_msec ms)
{
	t_msec			start;

	start = ft_current_time();
	while (ft_current_time() - start < ms)
		usleep(10);
}

static void	wrap_usleep(t_msec hell)
{
	t_msec			start;
	
	start = ft_current_time();
	hehe(hell);
	printf("SLEEP: %lu\n", ft_current_time() - start);
}

void	*philo_routine(void *args)
{
	while (1)
	{
		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0)
			printf("%lu is thinking\n", ((t_philo *)args)->index_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);

		pthread_mutex_lock(((t_philo *)args)->forks + ((t_philo *)args)->index_philo);
		pthread_mutex_lock(((t_philo *)args)->forks + (((t_philo *)args)->index_philo + 1 % ((t_philo *)args)->nb_philo));

		pthread_mutex_lock(((t_philo *)args)->death);
		((t_philo *)args)->last_meal = ft_current_time();
		pthread_mutex_unlock(((t_philo *)args)->death);

		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0)
			printf("%lu is eating\n", ((t_philo *)args)->index_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);
		wrap_usleep(((t_philo *)args)->time_to_eat);

		pthread_mutex_unlock(((t_philo *)args)->forks + ((t_philo *)args)->index_philo);
		pthread_mutex_unlock(((t_philo *)args)->forks + (((t_philo *)args)->index_philo + 1 % ((t_philo *)args)->nb_philo));

		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0)
			printf("%lu is sleeping\n", ((t_philo *)args)->index_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);
		wrap_usleep(((t_philo *)args)->time_to_sleep);
	}
	return (NULL);
}
