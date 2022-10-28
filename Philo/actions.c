/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:39:11 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/28 20:55:50 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_sitters *list)
{
	if (list->philo->stat == 1)
	{
		pthread_mutex_lock(&list->fork);
		pthread_mutex_lock(&list->philo->say_mutex);
		if (list->philo->stat == 1)
			printf("%zu\t%d\thas taken a fork\n",
				current_time() - list->time_start,
				list->philo_id);
		pthread_mutex_unlock(&list->philo->say_mutex);
		pthread_mutex_lock(&list->previous->fork);
		pthread_mutex_lock(&list->philo->say_mutex);
		if (list->philo->stat == 1)
			printf("%zu\t%d\thas taken a fork\n",
				current_time() - list->time_start,
				list->philo_id);
		pthread_mutex_unlock(&list->philo->say_mutex);
		return ;
	}
	return ;
}

void	eating(t_sitters *list)
{
	if (list->philo->stat == 1)
	{
		pthread_mutex_lock(&list->eat);
		list->last_meal = current_time();
		list->times_eating++;
		pthread_mutex_unlock(&list->eat);
		pthread_mutex_lock(&list->philo->say_mutex);
		if (list->philo->stat == 1)
			printf("%zu\t%d\tis eating\n",
				current_time() - list->time_start,
				list->philo_id);
		pthread_mutex_unlock(&list->philo->say_mutex);
		ft_usleep(list->philo->info.time_to_eat);
		return ;
	}
	return ;
}

void	unlock_fork(t_sitters *list)
{
	if (list->philo->info.philo_num > 1)
		pthread_mutex_unlock(&list->previous->fork);
	pthread_mutex_unlock(&list->fork);
}

void	sleeping(t_sitters *list)
{
	if (list->philo->stat == 1)
	{
		pthread_mutex_lock(&list->philo->say_mutex);
		if (list->philo->stat == 1)
			printf("%zu\t%d\tis sleeping\n",
				current_time() - list->time_start,
				list->philo_id);
		pthread_mutex_unlock(&list->philo->say_mutex);
		ft_usleep(list->philo->info.time_to_sleep);
		return ;
	}
	return ;
}

void	thinking(t_sitters *list)
{
	if (list->philo->stat == 1)
	{
		pthread_mutex_lock(&list->philo->say_mutex);
		if (list->philo->stat == 1)
			printf("%zu\t%d\tis thinking\n",
				current_time() - list->time_start,
				list->philo_id);
		pthread_mutex_unlock(&list->philo->say_mutex);
		return ;
	}
	return ;
}
