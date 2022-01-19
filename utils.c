/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:41:04 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 13:51:09 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

int	ft_atoi(char *txt)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (txt[i] == '-' || txt[i] == '+')
		i++;
	while (txt[i])
	{
		nb = nb * 10 + txt[i] - 48;
		i++;
	}
	if (txt[0] == '-')
		nb *= -1;
	return (nb);
}

int	check_atoi(char *txt)
{
	int	i;

	if (txt != NULL)
	{
		i = 0;
		while (txt[i])
		{
			if (txt[i] < '0' || txt[i] > '9')
				return (-1);
			i++;
		}
		return (1);
	}
	return (0);
}

long int	ft_print(char *txt, long int t, t_philosopher *philo)
{
	long int	time;

	if (t == 0)
		time = get_time();
	else
		time = t;
	pthread_mutex_lock(philo->text);
	if (*philo->stop == 0)
		printf("%ld : Philosopher %d %s\n", time, philo->number, txt);
	pthread_mutex_unlock(philo->text);
	return (time);
}
