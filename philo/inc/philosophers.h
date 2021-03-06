/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:13:17 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 05:51:51 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define PROGRAM_NAME	"philosophers"

typedef unsigned int	t_bool;

typedef unsigned long	t_msec;

typedef struct s_threads
{
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
	pthread_t		*philos;
	pthread_t		*medics;
}						t_threads;

typedef struct s_philo
{
	t_msec			begin_time;
	size_t			nb_philo;
	size_t			id_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_meals;
	t_msec			last_meal;
	t_bool			done;
	t_bool			died;
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
	pthread_t		philos;
	struct s_philo	*args;
}						t_philo;

///  ////////////////////////////////////////////////////  ///
///  ///          INPUT PARSING AND CHECKING          ///  ///
///  ////////////////////////////////////////////////////  ///

int			read_input(char *input[], size_t input_size);
//	Check if inputs are digits-strings, and if are valid integers.
t_philo		*parse_input(char *input[], size_t nb_philo);
//	Create args, as structure array, for each philosopher.

///  /////////////////////////////////////////////////////  ///
///  ///          THREADS AND MUTEX FUNCTIONS          ///  ///
///  /////////////////////////////////////////////////////  ///

int			init_mutex(t_threads *threads, t_philo *args, size_t nb_philo);
void		clear_mutex(t_threads *threads, size_t size);
void		clear_threads(t_threads *threads, size_t nb_philo);
int			init_threads(t_threads *threads, t_philo *args, size_t nb_philo);
int			allocate_mutex_threads(t_threads *threads, size_t nb_philo);
void		destroy_mutex_threads(t_threads *threads);

///  ///////////////////////////////////////////////  ///
///  ///          PHILOSOPHERS ROUTINES          ///  ///
///  ///////////////////////////////////////////////  ///

void		*philo_routine(void *args);
//	Philosopher main routine: thinking, eating, and sleeping.
void		*philo_death(void *args);
//	Philosopher keeper: monitoring philosopher starvation.
int			philo_thinking(t_philo *args);
int			philo_eating(t_philo *args);
int			philo_sleeping(t_philo *args);
int			philo_taking_forks(t_philo *args);
void		philo_release_forks(t_philo *args);

///  ///////////////////////////////  ///
///  ///          UTILS          ///  ///
///  ///////////////////////////////  ///

void		ft_sleep(t_msec ms);
//	Wrapper to usleep function, to enforce waiting time.
t_msec		ft_current_time(void);
//	Function to retrieve time since Epoch (01/01/70), in milliseconds.
size_t		ft_strlen(const char *s);
long		ft_atol(const char *nptr);
int			ft_aredigits(const char *str);

#endif
