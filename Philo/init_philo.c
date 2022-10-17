/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:30:41 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/17 13:57:43 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    chopstick_mutex(philo_t *philo, info_t *info)
{
    pthread_mutex_t *chopstick;
    philo_t *tmp;
    philo_t *first_philo;
    int             i;
    int s;
    
    first_philo = philo;
    while(i < info->philo_num)
    {
        chopstick = malloc(sizeof(pthread_mutex_t));
        s = pthread_mutex_init(&chopstick, NULL);
        if (s != 0)
            return (2);
        philo->chopstick[1] = chopstick;
        philo->next->chopstick[0] = chopstick; 
        tmp = philo;
        philo = philo->next;
        i++;
    }
    philo->next = first_philo;
}

void    *routine()
{
    printf("hi its me");
}

philo_t *init_philos(philo_t *philo, info_t *info)
{
    int s;
    int i;
    philo_t *first;
    philo_t *tmp;
    
    i = 0;
    first = philo;
    while(i < info->philo_num)
    {
        philo->id_philo = i;
        s = pthread_create(philo->philo, NULL, &routine, NULL);
        if (s != 0)
            return(1);
        tmp = philo;
        philo = philo->next;
        philo->previous = tmp;
        i++; 
    }
    philo->next = first;
    return (philo);
}

void    parsing(int argc, char **argv, info_t *info)
{
    info->philo_num = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    if(argc == 6)
        info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[4]);
}