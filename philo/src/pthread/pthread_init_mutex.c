/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_init_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:29:38 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:29:50 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_threads *threads, t_philo *args, size_t nb_philo)
{
	size_t			i;

	if (pthread_mutex_init(threads->death, NULL) != 0)
	{
		destroy_mutex_threads(threads);
		return (-1);
	}
	i = -1;
	while (++i < nb_philo)
	{
		args[i].death = threads->death;
		if (pthread_mutex_init(threads->forks + i, NULL) != 0)
		{
			clear_mutex(threads, i);
			destroy_mutex_threads(threads);
			return (-1);
		}
		args[i].forks = threads->forks;
	}
	return (0);
}
