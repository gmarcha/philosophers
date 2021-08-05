/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:29:27 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 19:31:16 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_eating(t_philo *args, int *index_meals)
{
	t_msec			timer;

	pthread_mutex_lock(args->forks + args->id_philo);
	pthread_mutex_lock(args->forks + (args->id_philo + 1 % args->nb_philo));
	pthread_mutex_lock(args->death);
	args->last_meal = ft_current_time();
	pthread_mutex_unlock(args->death);
	pthread_mutex_lock(args->death);
	timer = ft_current_time() - args->begin_time;
	if (args->died == 0)
		printf("%lu %lu is eating\n", timer, args->id_philo + 1);
	pthread_mutex_unlock(args->death);
	ft_sleep(args->time_to_eat);
	pthread_mutex_unlock(args->forks + args->id_philo);
	pthread_mutex_unlock(args->forks + (args->id_philo + 1 % args->nb_philo));
	(*index_meals)++;
	if (args->nb_meals >= 0 && *index_meals >= args->nb_meals)
	{
		pthread_mutex_lock(args->death);
		args->done = 1;
		pthread_mutex_unlock(args->death);
		return (1);
	}
	return (0);
}

void	*philo_routine(void *args)
{
	t_msec			timer;
	int				index_meals;

	index_meals = 0;
	while (1)
	{
		pthread_mutex_lock(((t_philo *)args)->death);
		timer = ft_current_time() - ((t_philo *)args)->begin_time;
		if (((t_philo *)args)->died == 0)
			printf("%lu %lu is thinking\n",
				timer, ((t_philo *)args)->id_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);
		if (philo_eating(args, &index_meals) == -1)
			return (NULL);
		pthread_mutex_lock(((t_philo *)args)->death);
		timer = ft_current_time() - ((t_philo *)args)->begin_time;
		if (((t_philo *)args)->died == 0)
			printf("%lu %lu is sleeping\n",
				timer, ((t_philo *)args)->id_philo + 1);
		pthread_mutex_unlock(((t_philo *)args)->death);
		ft_sleep(((t_philo *)args)->time_to_sleep);
	}
	return (NULL);
}
