/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:31:08 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/17 13:59:35 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct philo{
    pthread_t *philo;
    int id_philo;
    pthread_mutex_t *chopstick[2];
    int chops[2];
    struct philo *next;
    struct philo *previous;
}   philo_t;

//typedef struct tab{
//    philo_t philosopher;
//    struct tab *next;
//    struct tab *previous;
//}   tab_t;
typedef struct info{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}   info_t;

int     ft_atoi(const char *str);
void    parsing(int argc, char **argv, info_t *info);
philo_t *init_philos(philo_t *philo, info_t *info);

#endif