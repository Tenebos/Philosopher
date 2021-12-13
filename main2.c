/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:48:15 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/09 15:45:24 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	thread_launcher(t_philosopher *philosopher)
{
	pthread_create(&philosopher->t1, NULL, (void *)main_loop, philosopher);
}

void	init_philo(t_info *info, int i)
{
	info->conclave[i].time_to_eat = &info->time_to_eat;
	info->conclave[i].time_to_die = &info->time_to_die;
	info->conclave[i].time_to_sleep = &info->time_to_sleep;
	info->conclave[i].nbr_meat = &info->nbr_meat;
	info->conclave[i].is_eating = 0;
	info->conclave[i].is_dead = 0;
	info->conclave[i].stop = &info->stop;
	info->conclave[i].safe_stop = 0;
	info->conclave[i].ms = 0;
}

void	launcher(t_info *info)
{
	int	i;
	pthread_t	t1;

	i = 0;
	while (i < info->philo_nbr)
	{
		init_philo(info, i);
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
	i = 0;
	while (i < info->philo_nbr)
	{
		pthread_join(info->conclave[i].t1, NULL);
		i++;	
	}
	pthread_create(&t1, NULL, (void *)death_loop, info);
	pthread_join(t1, NULL);
}

int	main(int argc, char **argv)
{
	int	i;
	t_info	info;
	int	check;
//	pthread_t	t1;

	check = check_param(argc, argv);
	if (check < 0)
		return (0);
	init_info(&info, argv, argc);
	i = atoi(argv[1]);
	info.conclave = malloc(sizeof(t_philosopher) * i);
	info.forks = malloc(sizeof(pthread_mutex_t) * i);
	create_philosopher(&info, i);
	create_fork(&info, i);
	//	show_info(&info);
//	pthread_create(&t1, NULL, death_loop, &info);
	launcher(&info);
//	pthread_join(t1, NULL);
	//	i--;
	//	while (i >= 0)
	//	{
	//		analyze_philosopher(&(info.conclave[i]));
	//		i--;
	//	}
	//	i = 0;
	clean_philo(&info);
	return (1);
}
