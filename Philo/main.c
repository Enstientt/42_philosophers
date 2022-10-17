/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:23:47 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/17 11:41:22 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    info_t info;
    philo_t *philo;
    if (argc == 5 || argc == 6)
    {
        parsing(argc, argv, &info);
        philo = init_philos(&info, 0);
        pthread_join(philo->philo, NULL);
    }
    else if (argc == 1)
    {
        printf("Usage : ./philo ");
        printf("number_of_philosophers time_to_die time_to_eat ");
        printf("time_to_sleep");
        printf(" [number_of_times_each_philosopher_must_eat]");
    }
    else
         printf("wrong input");
}