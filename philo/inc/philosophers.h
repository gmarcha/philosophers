/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:13:17 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 16:08:42 by gamarcha         ###   ########.fr       */
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
	size_t			nb_philo;
	size_t			index_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_meals;
	t_msec			last_meal;
	t_bool			died;
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
	pthread_t		philos;
	struct s_philo	*args;
}						t_philo;

///  ///////////////////////////////////////  ///
///  ///          INPUT READING          ///  ///
///  ///////////////////////////////////////  ///

int			read_input(char *input[], size_t input_size);
//	Input validity check:
//	- input is a valid integer, and is integer overflowing.

///  ///////////////////////////////////////  ///
///  ///          INPUT PARSING          ///  ///
///  ///////////////////////////////////////  ///

t_philo		*parse_input(char *input[], size_t nb_philo);
//	Create args, as structure array, for pthread_create calls:
//	- parsing parameters in a specific structure for each philosophers.



void		*philo_routine(void *args);
void		*philo_death(void *args);

///  ///////////////////////////////  ///
///  ///          UTILS          ///  ///
///  ///////////////////////////////  ///

size_t		ft_strlen(const char *s);
long		ft_atol(const char *nptr);
int			ft_aredigits(const char *str);
t_msec		ft_current_time(void);
void		ft_sleep(t_msec ms);

#endif
