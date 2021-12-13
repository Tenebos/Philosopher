/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:23:21 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/03 09:52:09 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philosopher
{
	int	pid;
	pthread_mutex_t	*fork1;
	pthread_mutex_t *fork2;
	int	number;
	struct s_philosopher	*next;
}		t_philosopher;

typedef struct s_info
{
	t_philosopher	*conclave;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_think;
}	t_info;

// simulation
t_philosopher	*create_philosopher(int number, t_philosopher *previous, int last);
pthread_mutex_t	*init_mutex(void);
// int	rise_philosopher(t_philosopher *phil_rising);
void	launch_simulation(t_info *info);
void	*loop(void *param);

// cleaning
void	clean_conclave(t_philosopher *first);

// utils
int	ft_atoi(char *txt);
int	check_atoi(char *txt);

//debug
void	analyze_philosopher(t_philosopher *analyzed);	
