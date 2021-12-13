/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:25 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/13 17:13:21 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

int	check_param(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("not enought or too much parameters\n");
		return (-1);
	}
	while (i < argc)
	{
		check = check_atoi(argv[i]);
		if (check < 0)
		{
			printf("parameter error\n");
			return (-1);
		}
		i++;
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

int     create_philosopher(t_info *info, int end)
{
        int     i;

        i = 0;
        while (i < end)
        {
                info->conclave[i].number = i;
                info->conclave[i].pid = -1;
                i++;
        }
        return (1);
}

pthread_mutex_t init_mutex(void)
{
        pthread_mutex_t one = PTHREAD_MUTEX_INITIALIZER;
        return (one);
}

int     create_fork(t_info *info, int nb)
{
        int     i;

        i = 0;
        while (i < nb)
        {
                info->forks[i] = init_mutex();
                info->conclave[i].one = &info->forks[i];
                i++;
        }
        i = 0;
        while (i < nb)
        {
                if (i < nb)
                        info->conclave[i].two = &info->forks[i + 1];
                i++;
        }
        info->conclave[nb - 1].two = &info->forks[0];
}
