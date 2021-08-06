/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:12:20 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/06 07:49:35 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	handle_input_invalid(char *errmsg)
{
	printf("%s: %s\n", PROGRAM_NAME, errmsg);
	return (-1);
}

static int	input_check(char *input[], size_t input_size)
{
	long			tmp;

	if (ft_strlen(input[input_size]) > 10)
		return (handle_input_invalid("argument overflow"));
	tmp = ft_atol(input[input_size]);
	if (input_size == 4 || input_size == 0)
	{
		if (tmp > 2147483647)
			return (handle_input_invalid("argument overflow"));
		if (tmp == 0)
			return (-2);
	}
	if (input_size == 3 || input_size == 2)
	{
		if (tmp > 4294967)
			return (handle_input_invalid("argument overflow"));
	}
	return (0);
}

static int	is_input_valid(char *input[], size_t input_size)
{
	int				tmp;

	while (input_size != 0)
	{
		input_size--;
		if (ft_aredigits(input[input_size]) == 0)
			return (handle_input_invalid("argument is not an integer"));
		while (*input[input_size] == '0')
			input[input_size]++;
		tmp = input_check(input, input_size);
		if (tmp != 0)
			return (tmp);
	}
	return ((int)ft_atol(input[input_size]));
}

int	read_input(char *input[], size_t input_size)
{
	if (input_size == 1)
		return (handle_input_invalid("number of philosophers,"
				"time to die, time to eat, time to sleep, [number of meals]"));
	if (input_size < 5)
		return (handle_input_invalid("not enough arguments"));
	if (input_size > 6)
		return (handle_input_invalid("too much arguments"));
	return (is_input_valid(input + 1, input_size - 1));
}
