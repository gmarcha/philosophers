/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_clear_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:29:19 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:29:29 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_mutex(t_threads *threads, size_t size)
{
	while (size-- != 0)
		pthread_mutex_destroy(threads->forks + size);
	pthread_mutex_destroy(threads->death);
}
