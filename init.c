/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:25 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 15:09:01 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

int	check_param(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	if (argc != 5 && argc != 6)
		return (error("not enought or too much parameters\n"));
	while (i < argc)
	{
		check = check_atoi(argv[i]);
		if (check < 0)
			return (error("parameter error\n"));
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (error("not enought Philosophers"));
	if (ft_atoi(argv[1]) == 1)
	{
		usleep(atoi(argv[2]));
		printf("%ld : Philosopher 0 died\n", get_time());
		return (-1);
	}
	return (1);
}

void	init_info(t_info *info, char **argv, int ac)
{
	info->philo_nbr = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]) * 1000;
	info->time_to_sleep = ft_atoi(argv[4]) * 1000;
	info->text = init_mutex();
	if (ac == 6)
		info->nbr_meat = ft_atoi(argv[5]);
	else
		info->nbr_meat = -1;
	info->stop = 0;
}

int	create_philosopher(t_info *info, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		info->conclave[i].number = i;
		info->conclave[i].pid = -1;
		i++;
	}
	return (1);
}

pthread_mutex_t	init_mutex(void)
{
	pthread_mutex_t	one;

	pthread_mutex_init(&one, NULL);
	return (one);
}
