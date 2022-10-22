/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:34:30 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/22 12:03:55 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *args)
{
    
    t_sitters	*list;

	list = (t_sitters *)args;
	list->time_start = current_time();
	list->last_meal = list->time_start;
	if (list->philo_id % 2 == 0)
		ft_usleep(list->philo->info.time_to_eat);
	while (list->philo->stat == alive)
	{
		if (list->philo->info.philo_num == 1)
		{
			pthread_mutex_lock(&list->fork);
			pthread_mutex_lock(&list->philo->say_mutex);
			printf("MESSAGE HERE");
			pthread_mutex_unlock(&list->philo->say_mutex);
			ft_usleep(list->philo->info.time_to_die);
		}
        lock_fork(list);
        eating(list);
        unlock_fork(list);
        sleeping(list);
        thinking(list);
		ft_usleep(list->philo->info.time_to_eat);
	}
	return (NULL);   
}

void *check_death(void *args)
{
    return(NULL);
}
