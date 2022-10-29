/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:06:53 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/29 16:20:29 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_memory(t_philo *philo)
{
	t_sitters	*temp;
	int			index;

	index = philo->info.philo_num;
	while (index > 0)
	{
		temp = philo->table;
		philo->table = philo->table->next;
		free(temp);
		index--;
	}
}
