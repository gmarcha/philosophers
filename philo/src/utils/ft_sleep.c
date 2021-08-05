/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:34:12 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/05 18:34:21 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_msec ms)
{
	t_msec			start;

	start = ft_current_time();
	while (ft_current_time() - start < ms)
		usleep(100);
}
