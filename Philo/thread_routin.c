/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:34:30 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/21 20:10:09 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *args)
{
    
    t_sitters	*list;

	list = (t_sitters *)args;
	list->tiem_start = current_time();
	list->last_meal = list->tiem_start;
	if (list->philo_id % 2 == 0)
		ft_usleep(list->philo->info.time_to_eat);
	while (list->philo->stat == alive)
	{
		if (list->philo->info.philo_num == 1)
		{
			pthread_mutex_lock(&list->fork);
			printf("MESSAGE HERE");
			ft_usleep(list->philo->info.time_to_die);
		}
        //fork lock
        // eating
        // unlock the fork
        //sleeping
        // thinking
		ft_usleep(list->philo->info.time_to_eat);
	}
	return (NULL);   
}

void *check_death(void *args)
{
    return ;
}
