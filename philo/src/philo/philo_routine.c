/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:29:27 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 16:51:28 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *args)
{
	while (1)
	{
		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0)
			printf("%lu %lu is thinking\n", ft_current_time() - ((t_philo *)args)->begin_time, ((t_philo *)args)->index_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);

		pthread_mutex_lock(((t_philo *)args)->forks + ((t_philo *)args)->index_philo);
		pthread_mutex_lock(((t_philo *)args)->forks + (((t_philo *)args)->index_philo + 1 % ((t_philo *)args)->nb_philo));

		pthread_mutex_lock(((t_philo *)args)->death);
		((t_philo *)args)->last_meal = ft_current_time();
		pthread_mutex_unlock(((t_philo *)args)->death);

		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0)
			printf("%lu %lu is eating\n", ft_current_time() - ((t_philo *)args)->begin_time, ((t_philo *)args)->index_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);
		ft_sleep(((t_philo *)args)->time_to_eat);

		pthread_mutex_unlock(((t_philo *)args)->forks + ((t_philo *)args)->index_philo);
		pthread_mutex_unlock(((t_philo *)args)->forks + (((t_philo *)args)->index_philo + 1 % ((t_philo *)args)->nb_philo));

		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0)
			printf("%lu %lu is sleeping\n", ft_current_time() - ((t_philo *)args)->begin_time, ((t_philo *)args)->index_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);
		ft_sleep(((t_philo *)args)->time_to_sleep);
	}
	return (NULL);
}
