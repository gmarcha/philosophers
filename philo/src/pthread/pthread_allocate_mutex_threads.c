/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_allocate_mutex_threads.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:24:24 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:24:46 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	allocate_mutex_threads(t_threads *threads, size_t nb_philo)
{
	threads->death = malloc(sizeof(pthread_mutex_t));
	threads->forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	threads->philos = malloc(sizeof(pthread_t) * nb_philo);
	threads->medics = malloc(sizeof(pthread_t) * nb_philo);
	if (threads->death == NULL
		|| threads->forks == NULL
		|| threads->philos == NULL
		|| threads->medics == NULL)
	{
		if (threads->death != NULL)
			free(threads->death);
		if (threads->forks != NULL)
			free(threads->forks);
		if (threads->philos != NULL)
			free(threads->philos);
		if (threads->medics != NULL)
			free(threads->medics);
		return (-1);
	}
	return (0);
}
