/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_clear_threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:03:02 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 19:03:32 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_threads(t_threads *threads, size_t nb_philo)
{
	while (nb_philo-- != 0)
		pthread_join(threads->medics[nb_philo], NULL);
}
