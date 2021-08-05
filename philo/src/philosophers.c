/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:17:15 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 15:35:02 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	allocate_mutex_threads(t_threads *threads, size_t nb_philo)
{
	threads->death = malloc(sizeof(pthread_mutex_t));
	threads->forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	threads->philos = malloc(sizeof(pthread_t) * nb_philo);
	threads->medics = malloc(sizeof(pthread_t) * nb_philo);
	if (threads->forks == NULL
		|| threads->philos == NULL
		|| threads->medics == NULL)
	{
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

static void	destroy_mutex_threads(t_threads *threads)
{
	free(threads->death);
	free(threads->forks);
	free(threads->philos);
	free(threads->medics);
}

static void	clear_mutex(t_threads *threads, size_t size)
{
	while (size-- != 0)
		pthread_mutex_destroy(threads->forks + size);
	pthread_mutex_destroy(threads->death);
}

static int	init_mutex(t_threads *threads, t_philo *args, size_t nb_philo)
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

static int	init_threads(t_threads *threads, t_philo *args, size_t nb_philo)
{
	size_t			i;

	i = -1;
	while (++i < nb_philo)
	{
		args[i].last_meal = ft_current_time();
		pthread_create(threads->philos + i, NULL, philo_routine, args + i);
		args[i].philos = threads->philos[i];
		pthread_create(threads->medics + i, NULL, philo_death, args + i);
	}
	return (0);
}

static void	end_of_dinner(t_threads *threads, size_t nb_philo)
{
	size_t			i;

	i = -1;
	while (++i < nb_philo)
		pthread_join(threads->medics[i], NULL);
}

static void	dining_philosophers(t_philo *args, size_t nb_philo)
{
	t_threads		threads;

	if (allocate_mutex_threads(&threads, nb_philo) == -1)
		return ;
	if (init_mutex(&threads, args, nb_philo) == -1)
		return ;
	if (init_threads(&threads, args, nb_philo) == -1)
		return ;
	end_of_dinner(&threads, nb_philo);
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
