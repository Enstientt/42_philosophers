/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:23:47 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/25 14:28:07 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo philo;
    int     i;
    if (argc == 5)
    {
        philo = init_data(argv);
        if (init_0(&philo))
            printf("threads creation error\n");
    }
    if (argc == 1)
    {
        printf("Usage : ./philo ");
        printf("number_of_philosophers time_to_die time_to_eat ");
        printf("time_to_sleep");
        printf(" [number_of_times_each_philosopher_must_eat]");
    }
    if(argc > 5)
         printf("wrong input");
}