/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:34:12 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 15:12:02 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	*death_loop(t_info *faustine)
{
	int			i;
	long int	ms;

	i = 0;
	while (faustine->stop != 1)
	{
		ms = get_time();
		if ((faustine->conclave[i].ms + faustine->time_to_die < ms))
		{
			faustine->stop = 1;
			pthread_mutex_lock(&faustine->text);
			printf("%ld : Philosopher %d died\n", ms, i);
			pthread_mutex_unlock(&faustine->text);
		}
		if (faustine->conclave[i].enought_eat == 1)
		{
			enought(faustine);
		}
		if (i + 1 < faustine->philo_nbr)
			i++;
		else
			i = 0;
	}
	return (NULL);
}

void	*main_loop(t_philosopher *philo)
{
	int	i;

	i = 0;
	while (*philo->stop == 0)
	{
		ft_eat(philo);
		i++;
		ft_print("is sleeping", 0, philo);
		usleep(*philo->time_to_sleep);
		ft_print("is thinking", 0, philo);
		if (i == *philo->nbr_meat)
			philo->enought_eat = 1;
		usleep(1000);
	}
	return (NULL);
}

void	active_mutex(t_philosopher *philo, int pair)
{
	if (pair == 0)
		pthread_mutex_lock(philo->one);
	else
		pthread_mutex_lock(philo->two);
	if (pair == 0)
		pthread_mutex_lock(philo->two);
	else
		pthread_mutex_lock(philo->one);
}

void	desactive_mutex(t_philosopher *philo, int pair)
{
	if (pair == 0)
		pthread_mutex_unlock(philo->one);
	else
		pthread_mutex_unlock(philo->two);
	if (pair == 0)
		pthread_mutex_unlock(philo->two);
	else
		pthread_mutex_unlock(philo->one);
}

void	ft_eat(t_philosopher *philo)
{
	int	pair;

	pair = philo->number % 2;
	active_mutex(philo, pair);
	philo->ms = get_time();
	pthread_mutex_lock(philo->text);
	if (*philo->stop == 0)
	{
		printf("%ld : Philosopher %d has taken a fork\n",
			philo->ms, philo->number);
		printf("%ld : Philosopher %d is eating\n",
			philo->ms, philo->number);
	}
	pthread_mutex_unlock(philo->text);
	usleep(*philo->time_to_eat);
	desactive_mutex(philo, pair);
}
