/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:29:27 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 05:51:37 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_last_meal_time(t_philo *args)
{
	pthread_mutex_lock(args->death);
	args->last_meal = ft_current_time();
	pthread_mutex_unlock(args->death);
}

static int	update_index_meals(t_philo *args, int *index_meals)
{
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
	int				index_meals;

	index_meals = 0;
	while (1)
	{
		if (philo_thinking(args) == 1)
			return (NULL);
		if (philo_taking_forks(args) == 1)
			return (NULL);
		update_last_meal_time(args);
		if (philo_eating(args) == 1)
			return (NULL);
		philo_release_forks(args);
		if (update_index_meals(args, &index_meals) == 1)
			return (NULL);
		if (philo_sleeping(args) == 1)
			return (NULL);
	}
	return (NULL);
}
