/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:03:39 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/22 20:50:20 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_mutexs(t_philo *philo);

static int  init_threads(t_philo *philo);

static void join_threads(t_philo *philo);

void    init_0(t_philo *philo)
{
    int test;
    
    philo->table = init_table(philo);
    init_mutexs(philo);
    test = init_threads(philo);
    if(!test)
        printf("a philosopher doesn't show up ");
    join_threads(philo);
}

static void init_mutexs(t_philo *philo)
{
    t_sitters *temp;
    int size;

    temp = philo->table;
    size = philo->table->table_size;
    pthread_mutex_init(&philo->say_mutex, NULL);
    while (size)
    {
        pthread_mutex_init(&temp->eat, NULL);
        pthread_mutex_init(&temp->fork, NULL);
        temp = temp->next; 
        size--;
    }
}

static  int init_threads(t_philo *philo)
{
    t_sitters *tmp;
    int index;
    int test;
    
    tmp = philo->table;
    index = philo->table->table_size;
    while (index > 0)
    {
        tmp->last_meal = 0;
        test = pthread_create(&tmp->thread, NULL, &routine, (void *)tmp);
        if(test)
            return (0);
        index--;
        tmp = tmp->next;  
    }
    test = pthread_create(&philo->death, NULL, &check_death, (void *)philo->table);
    if (test)
        return (0);
    return (1);
}

static void join_threads(t_philo *philo)
{
    t_sitters *tmp;
    int index;
    
    tmp = philo->table;
    index = philo->table->table_size;
    pthread_join(philo->death, NULL);
    while (index)
    {
        pthread_join(tmp->thread, NULL);
        index--;
        tmp = tmp->next;
    }
}