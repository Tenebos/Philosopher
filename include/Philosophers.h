/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:23:21 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 15:04:02 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philosopher
{
	int			pid;
	int			number;
	t_mutex		*one;
	t_mutex		*two;
	t_mutex		*text;
	const int	*time_to_eat;
	const int	*time_to_sleep;
	const int	*time_to_die;
	const int	*nbr_meat;
	int			enought_eat;
	long int	ms;
	int			is_dead;
	int			*stop;
	int			safe_stop;
	pthread_t	t1;
}			t_philosopher;

typedef t_philosopher	t_philo;

typedef struct s_info
{
	t_philo	*conclave;
	t_mutex	*forks;
	t_mutex	text;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		philo_nbr;
	int		nbr_meat;
	int		stop;
}		t_info;

//loop
void		active_mutex(t_philosopher *philo, int pair);
void		desactive_mutex(t_philosopher *philo, int pair);
void		ft_eat(t_philosopher *philo);
void		*death_loop(t_info *info);
void		stop_all_loops(t_info *faustine);
void		enought(t_info *faustine);

// time
long		get_time(void);

// parsing;
int			check_param(int argc, char **argv);
void		init_info(t_info *info, char **argv, int ac);

// init;
int			create_philosopher(t_info *info, int end);
t_mutex		init_mutex(void);
void		create_fork(t_info *info, int i);
void		create_fork_one(t_info *info);
void		init_philo(t_info *info, int i, long int time);

//simulation
// int	rise_philosopher(t_philosopher *phil_rising);
void		launcher(t_info *info);
void		thread_launcher(t_philosopher *philosopher);
void		*main_loop(t_philosopher *philo);

// cleaning
void		clean_philo(t_info *info);

// utils
int			ft_atoi(char *txt);
int			check_atoi(char *txt);
long int	ft_print(char *txt, long int t, t_philosopher *philo);

//debug
void		analyze_philosopher(const t_philosopher *analyzed);
void		show_info(const t_info *info);

#endif
