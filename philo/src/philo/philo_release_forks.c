/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_release_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 05:51:06 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 05:52:43 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_release_forks(t_philo *args)
{
	pthread_mutex_unlock(args->forks + args->id_philo);
	pthread_mutex_unlock(args->forks + (args->id_philo + 1 % args->nb_philo));
}
