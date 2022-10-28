/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:55:57 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/28 21:16:41 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + (current_time.tv_usec / 1000));
}

void	ft_usleep(size_t usec)
{
	size_t	start_time;

	start_time = current_time();
	usleep((usec - 10) * 1000);
	while ((current_time() - usec) < start_time)
		;
}
