/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:39:11 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/25 14:53:55 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    lock_fork(t_sitters *list)
{
    if (list->philo->stat == 1)
    {
        pthread_mutex_lock(&list->fork);
        //pthread_mutex_lock(&list->philo->say_mutex);
        printf("%zu\t%d\thas taken a fork\n",
            current_time() - list->time_start, list->philo_id);
        //pthread_mutex_unlock(&list->philo->say_mutex);
        pthread_mutex_lock(&list->previous->fork);
        //pthread_mutex_lock(&list->philo->say_mutex);
        printf("%zu\t%d\thas taken a fork\n",
            current_time() - list->time_start, list->philo_id);
        //pthread_mutex_unlock(&list->philo->say_mutex);
    }
}

void    eating(t_sitters *list)
{
    t_sitters *temp;
   
   temp = list;
   pthread_mutex_lock(&temp->eat);
   list->last_meal = current_time();
   list->times_eating++;
   //pthread_mutex_lock(&temp->philo->say_mutex);
   if (list->philo->stat == 1)
       printf("%zu\t%d\tis eating\n", current_time() - list->time_start, list->philo_id);
   //pthread_mutex_unlock(&temp->philo->say_mutex);
   ft_usleep(temp->philo->info.time_to_eat);
}

void    unlock_fork(t_sitters *list)
{
    t_sitters   *temp;

    temp = list;
    pthread_mutex_unlock(&temp->fork);
    pthread_mutex_unlock(&temp->previous->fork);
}

void    sleeping(t_sitters *list)
{
    t_sitters *temp;
    //pthread_mutex_lock(&temp->philo->say_mutex);
    printf("%zu\t%d\tis sleeping\n",
        current_time() - temp->time_start,
        temp->philo_id);
    //pthread_mutex_unlock(&temp->philo->say_mutex);
    ft_usleep(temp->philo->info.time_to_sleep);
}

void    thinking(t_sitters *list)
{
    //pthread_mutex_lock(&list->philo->say_mutex);
    if (list->philo->stat == 1)
        printf("%zu\t%d\tis thinking\n",
        current_time() - list->time_start,
        list->philo_id);
    //pthread_mutex_unlock(&list->philo->say_mutex);
}