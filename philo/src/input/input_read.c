/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:12:20 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:42:29 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	handle_input_invalid(char *errmsg)
{
	printf("%s: %s\n", PROGRAM_NAME, errmsg);
	return (-1);
}

static int	is_input_valid(char *input[], size_t input_size)
{
	while (input_size != 0)
	{
		input_size--;
		if (ft_aredigits(input[input_size]) == 0)
			return (handle_input_invalid("argument is not an integer"));
		while (*input[input_size] == '0')
			input[input_size]++;
		if (ft_strlen(input[input_size]) > 10
			|| ft_atol(input[input_size]) > 2147483647l)
			return (handle_input_invalid("argument overflow"));
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
