/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:54:45 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/21 18:48:49 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_sitters    *new_philo(t_philo *philo, int id)
{
    t_sitters   *new;
    
    new = malloc(sizeof(t_sitters));
    if(!new)
        return (NULL);
    new->last_meal = 0;
    new->philo_id = id;
    new->philo = philo;
    new->table_size = philo->info.philo_num;
    new->next = new;
    new->previous = new;
    return (new);
}
    

void    add_p_totable(t_sitters *list, t_sitters *new)
{
    if (list)
    {
        new->next = list->next;
		new->previous = list;
		list->next->previous = new;
		list->next = new;
		list = new;
    }
    else
        list = new;
}

t_sitters *init_table(t_philo *philo)
{
    t_sitters   *list;
    t_sitters   *temp;
    int index;
    
    index = 1;
    list = new_philo(philo, philo->info.philo_num);
    while (index < philo->info.philo_num)
    {
        temp = new_philo(philo, index);
        add_p_totable(list, temp);
        index++;     
    }
    return (list);
}
