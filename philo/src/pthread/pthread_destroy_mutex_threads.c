/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_destroy_mutex_threads.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:27:32 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:28:30 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex_threads(t_threads *threads)
{
	free(threads->death);
	free(threads->forks);
	free(threads->philos);
	free(threads->medics);
}
