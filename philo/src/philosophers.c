/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:17:15 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/03 19:02:54 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	allocate_threads(pthread_t **philos, pthread_mutex_t **forks, size_t nb_philo)
{
	*philos = (pthread_t *)malloc(sizeof(pthread_t) * nb_philo);
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (*philos == NULL || *forks == NULL)
	{
		if (*philos != NULL)
			free(*philos);
		if (*forks != NULL)
			free(*forks);
		return (-1);
	}
	return (0);
}

static void	*destroy_threads(pthread_t *philos, pthread_mutex_t *forks)
{
	free(philos);
	free(forks);
	return (NULL);
}

static void	*clear_mutex(pthread_t *philos, pthread_mutex_t *forks, size_t size)
{
	while (size-- != 0)
		if (pthread_mutex_destroy(forks + size) != 0)
			return (destroy_threads(philos, forks));
	return (destroy_threads(philos, forks));
}

static void	*clear_threads(pthread_t *philos, pthread_mutex_t *forks, size_t nb_philo, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
		if (pthread_detach(philos[i++]) != 0)
			return (clear_mutex(philos, forks, nb_philo));
	return (clear_mutex(philos, forks, nb_philo));
}

void	*philo_routine(void *args)
{
	printf("%lu is thinking\n", ((t_philo *)args)->index_philo + 1);
	pthread_mutex_lock(((t_philo *)args)->forks + ((t_philo *)args)->index_philo);
	pthread_mutex_lock(((t_philo *)args)->forks + (((t_philo *)args)->index_philo + 1 % ((t_philo *)args)->nb_philo));
	printf("%lu is eating\n", ((t_philo *)args)->index_philo + 1);
	usleep((useconds_t)(((t_philo *)args)->time_to_eat * 1000));
	pthread_mutex_unlock(((t_philo *)args)->forks + ((t_philo *)args)->index_philo);
	pthread_mutex_unlock(((t_philo *)args)->forks + (((t_philo *)args)->index_philo + 1 % ((t_philo *)args)->nb_philo));
	printf("%lu is sleeping\n", ((t_philo *)args)->index_philo + 1);
	usleep((useconds_t)(((t_philo *)args)->time_to_sleep * 1000));
	return (NULL);
}

void	*create_threads(t_philo *args, size_t nb_philo)
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	size_t			i;

	philos = 0;
	forks = 0;
	if (allocate_threads(&philos, &forks, nb_philo) == -1)
		return (NULL);
	i = -1;
	while (++i < nb_philo)
		if (pthread_mutex_init(forks + i, NULL) != 0)
			return (clear_mutex(philos, forks, i));
	i = 0;
	while (i < nb_philo)
		args[i++].forks = forks;
	i = -1;
	while (++i < nb_philo)
		if (pthread_create(philos + i, NULL, philo_routine, args + i) != 0)
			return (clear_threads(philos, forks, nb_philo, i));
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_join(philos[i], NULL) != 0)
			return (clear_mutex(philos, forks, nb_philo));
		printf("%lu died\n", philos[i]);
		i++;
	}
	return (clear_mutex(philos, forks, nb_philo));
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
	create_threads(args, (size_t)nb_philo);
	free(args);
	return (EXIT_SUCCESS);
}
