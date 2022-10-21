/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:31:08 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/21 18:43:00 by zessadqu         ###   ########.fr       */
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

typedef enum statue{
    alive,
    died
}   e_statue;

typedef struct s_info{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}   t_info;

typedef struct s_sitters{
    int philo_id;
    int last_meal;
    int tiem_start;
    pthread_t thread;
    pthread_mutex_t fork;
    pthread_mutex_t eat;
    struct s_philo *philo;
    struct s_sitters *next;
    struct s_sitters *previous;
    int table_size;
}   t_sitters;

typedef struct s_philo{
    pthread_t death;
    pthread_mutex_t say_mutex;
    e_statue stat;
    t_info info;
    t_sitters *table;
}   t_philo;

int     ft_atoi(const char *str);
t_philo init_data(char **argv);
void    init_0(t_philo *philo);
t_sitters *init_table(t_philo *philo);
void *routine(void *args);
void *check_death(void *args);
t_sitters *init_table(t_philo *philo);
t_sitters    *new_philo(t_philo *philo, int id);
void    add_p_totable(t_sitters *list, t_sitters *new);

#endif