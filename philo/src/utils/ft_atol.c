/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:33:44 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:33:46 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	long			result;
	int				sign;
	int				i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		sign *= (nptr[i++] & 2) - 1;
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - 48;
	return (result * sign);
}
