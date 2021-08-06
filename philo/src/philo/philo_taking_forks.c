/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_taking_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 05:50:58 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 06:18:52 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	take_fork(t_philo *args, size_t id_fork)
{
	t_bool			ret;
	t_msec			timer;

	pthread_mutex_lock(args->forks + id_fork);
	printf("How ?\n");
	ret = 1;
	pthread_mutex_lock(args->death);
	timer = ft_current_time() - args->begin_time;
	if (args->died == 0)
	{
		ret = 0;
		printf("%lu %lu has taken a fork\n", timer, args->id_philo + 1);
	}
	pthread_mutex_unlock(args->death);
	return (ret);
}

int	philo_taking_forks(t_philo *args)
{
	printf("GO LEFT: %lu\n", args->id_philo);
	if (take_fork(args, args->id_philo) == 1)
	{
		pthread_mutex_unlock(args->forks + args->id_philo);
		return (1);
	}
	printf("GO RIGHT: %lu\n", args->id_philo + 1 % args->nb_philo);
	if (take_fork(args, args->id_philo + 1 % args->nb_philo) == 1)
	{
		pthread_mutex_unlock(args->forks + args->id_philo);
		pthread_mutex_unlock(args->forks + args->id_philo + 1 % args->nb_philo);
		return (1);
	}
	return (0);
}
