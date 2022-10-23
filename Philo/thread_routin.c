/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:34:30 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/23 15:18:20 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_sitters *list);

void	unlock_all(t_sitters *list);

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
			printf(" %zu   MESSAGE HERE\n", current_time() - list->time_start);
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
	t_sitters *list;

	list = (t_sitters *)args;
	ft_usleep(10);
	while (list->philo->stat == alive)
	{
		pthread_mutex_lock(&list->eat);
		pthread_mutex_lock(&list->philo->say_mutex);
		if (check_meals(list))
			break;
		if (current_time() - list->last_meal >= list->philo->info.time_to_die)
		{
			list->philo->stat = died;
			printf("%zu  [THE PHILO] DIED\n", current_time() - list->time_start);
			break;
		}
		pthread_mutex_unlock(&list->philo->say_mutex);
		pthread_mutex_unlock(&list->eat);
		list = list->next;
	}
	unlock_all(list);
	return (NULL);
}

void	unlock_all(t_sitters *list)
{
	t_sitters *temp;
	int	index;
	
	temp = list;
	index = list->table_size;
	list->philo->stat = died;
	pthread_mutex_unlock(&list->philo->say_mutex);
	pthread_mutex_destroy(&list->philo->say_mutex);
	while (index > 0 )
	{
		pthread_mutex_unlock(&temp->eat);
		pthread_mutex_destroy(&temp->eat);
		pthread_mutex_unlock(&temp->fork);
		pthread_mutex_destroy(&temp->fork);
		temp = temp->next;
		index--;
	}
}

int	check_meals(t_sitters *list)
{
	t_sitters	*temp;
	int	index;
	int	check;
	
	temp = list;
	index = list->table_size;
	check = 1;
	while(index > 0)
	{
		if (temp->philo->info.number_of_times_each_philosopher_must_eat 
			|| temp->times_eating < temp->philo->info.number_of_times_each_philosopher_must_eat)
			check = 0;
		temp = temp->next;
		index--;
	}
}