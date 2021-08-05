/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:29:29 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 19:27:19 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_death(void *args)
{
	t_msec			timer;
	size_t			i;

	while (((t_philo *)args)->died == 0)
	{
		pthread_mutex_lock(((t_philo *)args)->death);
		timer = ft_current_time() - ((t_philo *)args)->last_meal;
		if (((t_philo *)args)->done == 1)
			((t_philo *)args)->died = 1;
		else if (((t_philo *)args)->died == 0
			&& timer > ((t_philo *)args)->time_to_die)
		{
			timer = ft_current_time() - ((t_philo *)args)->begin_time;
			printf("%lu %lu died\n", timer, ((t_philo *)args)->id_philo + 1);
			i = -1;
			while (++i < ((t_philo *)args)->nb_philo)
				((t_philo *)args)->args[i].died = 1;
		}
		pthread_mutex_unlock(((t_philo *)args)->death);
	}
	pthread_detach(((t_philo *)args)->philos);
	return (NULL);
}
