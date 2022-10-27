/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:30:41 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/27 00:26:00 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo    init_data(char **argv)
{
    t_philo philo;
    
    philo.info.philo_num = ft_atoi(argv[1]);
    philo.info.time_to_die = ft_atoi(argv[2]);
    philo.info.time_to_eat = ft_atoi(argv[3]);
    philo.info.time_to_sleep = ft_atoi(argv[4]);
    philo.stat = 1;
    if(argv[5])
        philo.info.opt = ft_atoi(argv[5]);
    else
        philo.info.opt = 0;
    return (philo);
}