/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:31:08 by zessadqu          #+#    #+#             */
/*   Updated: 2022/10/29 16:17:01 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

typedef enum statue
{
	died,
	alive
}	t_statue;

typedef struct s_info
{
	int		philo_num;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		opt;
}	t_info;

typedef struct s_sitters
{
	int					philo_id;
	int					times_eating;
	size_t				last_meal;
	size_t				time_start;
	pthread_t			thread;
	pthread_mutex_t		fork;
	pthread_mutex_t		eat;
	struct s_philo		*philo;
	struct s_sitters	*next;
	struct s_sitters	*previous;
	int					table_size;
}	t_sitters;

typedef struct s_philo
{
	pthread_t		death;
	pthread_mutex_t	say_mutex;
	t_statue		stat;
	t_info			info;
	t_sitters		*table;
}	t_philo;

int			ft_atoi(const char *str);
int			init_0(t_philo *philo);
void		add_p_totable(t_sitters *list, t_sitters *new);
void		lock_fork(t_sitters *list);
void		eating(t_sitters *list);
void		unlock_fork(t_sitters *list);
void		sleeping(t_sitters *list);
void		thinking(t_sitters *list);
void		*routine(void *args);
void		*check_death(void *args);
t_philo		init_data(char **argv);
t_sitters	*init_table(t_philo *philo);
t_sitters	*new_philo(t_philo *philo, int id);
size_t		current_time(void);
void		ft_usleep(size_t usec);
int			args(char **argv);
void		free_memory(t_philo *philo);
int			ft_isdigit(int c);

#endif