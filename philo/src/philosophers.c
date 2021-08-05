/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:17:15 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 19:02:53 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	dining_philosophers(t_philo *args, size_t nb_philo)
{
	t_threads		threads;

	if (allocate_mutex_threads(&threads, nb_philo) == -1)
		return ;
	if (init_mutex(&threads, args, nb_philo) == -1)
		return ;
	if (init_threads(&threads, args, nb_philo) == -1)
		return ;
	clear_threads(&threads, nb_philo);
	clear_mutex(&threads, nb_philo);
	destroy_mutex_threads(&threads);
}

int	main(int ac, char *av[])
{
	int				nb_philo;
	t_philo			*args;

	nb_philo = read_input(av, (size_t)ac);
	if (nb_philo == -1)
		return (EXIT_FAILURE);
	args = parse_input(av + 1, (size_t)nb_philo);
	if (args == NULL)
		return (EXIT_FAILURE);
	dining_philosophers(args, (size_t)nb_philo);
	free(args);
	return (EXIT_SUCCESS);
}
