/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 05:43:04 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 05:43:15 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eating(t_philo *args)
{
	t_bool			ret;
	t_msec			timer;

	ret = 1;
	pthread_mutex_lock(args->death);
	timer = ft_current_time() - args->begin_time;
	if (args->died == 0)
	{
		ret = 0;
		printf("%lu %lu is eating\n", timer, args->id_philo + 1);
	}
	pthread_mutex_unlock(args->death);
	if (ret == 1)
		return (1);
	ft_sleep(args->time_to_eat);
	return (0);
}
