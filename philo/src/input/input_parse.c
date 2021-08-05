/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:07:29 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 19:27:19 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*parse_input(char *input[], size_t nb_philo)
{
	t_philo			*args;
	size_t			i;

	args = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	if (args == NULL)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		args[i].nb_philo = nb_philo;
		args[i].id_philo = i;
		args[i].time_to_die = (size_t)ft_atol(input[1]);
		args[i].time_to_eat = (size_t)ft_atol(input[2]);
		args[i].time_to_sleep = (size_t)ft_atol(input[3]);
		if (input[4] != NULL)
			args[i].nb_meals = (int)ft_atol(input[4]);
		else
			args[i].nb_meals = -1;
		args[i].done = 0;
		args[i].died = 0;
		args[i].args = args;
		i++;
	}
	return (args);
}
