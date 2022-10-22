/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:39:11 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/22 12:09:41 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    lock_fork(t_sitters *list)
{
    if (list->philo->stat == alive)
    {
        pthread_mutex_lock(&list->fork);
        pthread_mutex_lock(&list->philo->say_mutex);
        printf("[TIME]  [THE PHILO] has taken a fork");
        pthread_mutex_unlock(&list->philo->say_mutex);
        pthread_mutex_lock(&list->previous->fork);
        pthread_mutex_lock(&list->philo->say_mutex);
        printf("[TIME]  [THE PHILO] has taken a fork");
        pthread_mutex_unlock(&list->philo->say_mutex);
    }
}

void    eating(t_sitters *list)
{
    if (list->philo->stat == alive)
    {
        pthread_mutex_lock(&list->philo->say_mutex);
        pthread_mutex_lock(&list->eat);
        printf("[TIME]  [THE PHILO] has taken a fork");
        pthread_mutex_unlock(&list->philo->say_mutex);
    }
}

void    unlock_fork(t_sitters *list)
{
    pthread_mutex_unlock(&list->fork);
    pthread_mutex_unlock(&list->previous->fork);
}

void    sleeping(t_sitters *list)
{
    pthread_mutex_lock(&list->philo->say_mutex);
    printf("[TIME] [THE PHILO] is sleeping");
    pthread_mutex_unlock(&list->philo->say_mutex);
}

void    thinking(t_sitters *list)
{
    pthread_mutex_lock(&list->philo->say_mutex);
    printf("[TIME] [THE PHILO] is thinking");
    pthread_mutex_unlock(&list->philo->say_mutex);
}