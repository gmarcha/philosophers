/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:29:29 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 16:11:12 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_death(void *args)
{
	size_t			i;

	while (((t_philo *)args)->died == 0)
	{
		pthread_mutex_lock(((t_philo *)args)->death);
		if (((t_philo *)args)->died == 0
			&& ft_current_time() - ((t_philo *)args)->last_meal > ((t_philo *)args)->time_to_die)
		{
			printf("%lu died\n", ((t_philo *)args)->index_philo + 1);
			i = -1;
			while (++i < ((t_philo *)args)->nb_philo)
				((t_philo *)args)->args[i].died = 1;
		}
		pthread_mutex_unlock(((t_philo *)args)->death);
	}
	pthread_detach(((t_philo *)args)->philos);
	return (NULL);
}
