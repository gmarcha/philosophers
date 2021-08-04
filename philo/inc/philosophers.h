/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarcha <gmarcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:13:17 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/04 13:33:07 by gmarcha          ###   ########.fr       */
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

typedef unsigned long	t_msec;

typedef struct s_philo
{
	size_t			nb_philo;
	size_t			index_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_meals;
	pthread_mutex_t	*forks;
}						t_philo;

///  ///////////////////////////////////////  ///
///  ///          INPUT READING          ///  ///
///  ///////////////////////////////////////  ///

int			read_input(char *input[], size_t input_size);
/*	Input validity check:									*/
/*	- input is a valid integer, and is integer overflowing.	*/

///  ///////////////////////////////////////  ///
///  ///          INPUT PARSING          ///  ///
///  ///////////////////////////////////////  ///

t_philo		*parse_input(char *input[], size_t nb_philo);
/*	Create args, as structure array,  for pthread_create calls:			*/
/*	- parsing parameters in a specific structure for each philosophers.	*/

///  ///////////////////////////////  ///
///  ///          UTILS          ///  ///
///  ///////////////////////////////  ///

size_t		ft_strlen(const char *s);
long		ft_atol(const char *nptr);
int			ft_aredigits(const char *str);
t_msec		ft_current_time(void);

#endif
