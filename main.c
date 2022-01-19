/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:48:15 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 14:03:29 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	thread_launcher(t_philosopher *philosopher)
{
	pthread_create(&philosopher->t1, NULL, (void *)main_loop, philosopher);
}

void	init_philo(t_info *info, int i, long int time)
{
	info->conclave[i].time_to_eat = &info->time_to_eat;
	info->conclave[i].time_to_die = &info->time_to_die;
	info->conclave[i].time_to_sleep = &info->time_to_sleep;
	info->conclave[i].nbr_meat = &info->nbr_meat;
	info->conclave[i].enought_eat = 0;
	info->conclave[i].text = &info->text;
	info->conclave[i].is_dead = 0;
	info->conclave[i].stop = &info->stop;
	info->conclave[i].safe_stop = 0;
	info->conclave[i].ms = time;
}

static int	launcher2(t_info *info, int i, long int time)
{
	while (i < info->philo_nbr)
	{
		init_philo(info, i, time);
		i++;
	}
	i = 0;
	while (i < info->philo_nbr)
	{
		if (i % 2 == 0)
			thread_launcher(&info->conclave[i]);
		i++;
	}
	i = 0;
	while (i < info->philo_nbr)
	{
		if (i % 2 == 1)
			thread_launcher(&info->conclave[i]);
		i++;
	}
	return (i);
}

void	launcher(t_info *info)
{
	int			i;
	pthread_t	t1;
	long int	time;

	i = 0;
	time = get_time();
	i = launcher2(info, i, time);
	pthread_create(&t1, NULL, (void *)death_loop, info);
	i = 0;
	while (i < info->philo_nbr)
	{
		pthread_join(info->conclave[i].t1, NULL);
		i++;
	}
	pthread_join(t1, NULL);
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	int		check;

	check = check_param(argc, argv);
	if (check < 0)
		return (0);
	init_info(&info, argv, argc);
	i = atoi(argv[1]);
	info.conclave = malloc(sizeof(t_philosopher) * i);
	info.forks = malloc(sizeof(pthread_mutex_t) * i);
	create_philosopher(&info, i);
	if (i != 1)
		create_fork(&info, i);
	launcher(&info);
	clean_philo(&info);
	return (1);
}
