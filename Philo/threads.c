/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:03:39 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/28 21:10:57 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexs(t_philo *philo);

static int	init_threads(t_philo *philo);

static int	detach_threads(t_philo *philo);

static int	join_threads(t_philo *philo);

int	init_0(t_philo *philo)
{
	int	test;

	philo->table = init_table(philo);
	init_mutexs(philo);
	if (init_threads(philo)
		|| join_threads(philo))
		return (1);
	return (0);
}

static int	init_mutexs(t_philo *philo)
{
	t_sitters	*temp;
	int			size;

	temp = philo->table;
	size = philo->table->table_size;
	if (pthread_mutex_init(&philo->say_mutex, NULL))
		return (1);
	while (size > 0)
	{
		if (pthread_mutex_init(&temp->eat, NULL)
			|| pthread_mutex_init(&temp->fork, NULL))
			return (1);
		temp = temp->next;
		size--;
	}
	return (0);
}

static int	init_threads(t_philo *philo)
{
	t_sitters	*tmp;
	int			index;

	tmp = philo->table;
	index = philo->table->table_size;
	while (index > 0)
	{
		tmp->last_meal = 0;
		if (pthread_create(&tmp->thread, NULL, &routine, (void *)tmp))
			return (1);
		index--;
		tmp = tmp->previous;
	}
	if (pthread_create(&philo->death, NULL, &check_death, (void *)philo->table))
		return (1);
	return (0);
}

static int	join_threads(t_philo *philo)
{
	t_sitters	*tmp;
	int			index;

	tmp = philo->table;
	index = philo->table->table_size;
	if (pthread_join(philo->death, NULL))
		return (1);
	while (index > 0)
	{
		if (pthread_join(tmp->thread, NULL))
			return (1);
		tmp = tmp->next;
		index--;
	}
	return (0);
}

static int	detach_threads(t_philo *philo)
{
	int			index;
	t_sitters	*tmp;

	index = philo->info.philo_num;
	tmp = philo->table;
	if (pthread_detach(tmp->philo->death))
		return (1);
	while (index > 0)
	{
		if (pthread_detach(tmp->thread))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
