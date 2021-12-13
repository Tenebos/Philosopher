/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:23:21 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/13 16:54:58 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int	pid;
	int	number;
	pthread_mutex_t	*one;
	pthread_mutex_t	*two;
	pthread_mutex_t *text;
	const int	*time_to_eat;
	const int	*time_to_sleep;
	const int	*time_to_die;
	const int	*nbr_meat;
	int		is_eating;
	long		ms;
	int		is_dead;
	int		*stop;
	int		safe_stop;
	pthread_t	t1;
}		t_philosopher;

typedef struct s_info
{
	t_philosopher	*conclave;
	pthread_mutex_t	*forks;
	pthread_mutex_t text;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	philo_nbr;
	int	nbr_meat;
	int	stop;
}	t_info;

//loop
void	active_mutex(t_philosopher *philo);
void	desactive_mutex(t_philosopher *philo);
void	ft_eat(t_philosopher *philo);
void	*death_loop(t_info *info);
void	stop_all_loops(t_info *faustine);

// time
long	get_time(void);


// parsing;
int	check_param(int argc, char **argv);
void	init_info(t_info *info, char **argv, int ac);


// init;
int	create_philosopher(t_info *info, int end);
pthread_mutex_t	init_mutex(void);
int	create_fork(t_info *info, int i);
void	init_philo(t_info *info, int i);

//simulation
// int	rise_philosopher(t_philosopher *phil_rising);
void	launcher(t_info *info);
void	thread_launcher(t_philosopher *philosopher);
void	*main_loop(t_philosopher *philo);


// cleaning
void	clean_philo(t_info *info);


// utils
int	ft_atoi(char *txt);
int	check_atoi(char *txt);
void	ft_print(char *txt, int nb, pthread_mutex_t *t1, int stop);

//debug
void	analyze_philosopher(const t_philosopher *analyzed);
void	show_info(const t_info *info);

#endif
