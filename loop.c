/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:34:12 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/13 15:02:14 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	*death_loop(t_info *faustine)
{
	int	i;
	long	ms;

	i = 0;
	while (faustine->stop != 1)
	{
		ms = get_time();
		if ((faustine->conclave[i].ms + faustine->time_to_die < ms))
		{
			printf("Le philosophe %d meurt\n", faustine->conclave[i].number);	
			faustine->stop = 1;
		}
		i++;
	}
	i = 0;
	stop_all_loops(faustine);
	while (i < faustine->philo_nbr)
	{
		printf("philosophe %d is stopped ? %d\n", faustine->conclave[i].number, faustine->conclave[i].safe_stop);
		i++;
	}
}

void	stop_all_loops(t_info *faustine)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (check != 1)
	{
		i = 0;
		while (i < faustine->philo_nbr)
		{
			check = 1;
			if (faustine->conclave[i].safe_stop != 1)
			{
				*faustine->conclave[i].stop = 1;
				if (faustine->conclave[i].is_eating == 1)
				{
					desactive_mutex(&faustine->conclave[i]);
					faustine->conclave[i].is_eating = 0;
				}
				check = 0;
			}
			i++;
		}
		i = 0;
	}
	i = 0;
}

void    *main_loop(t_philosopher *philo)
{
	int     i;
	long    ms2;
	long    ms;


	i = 0;
	while (*philo->stop == 0 && i != *philo->nbr_meat)
	{
		if (*philo->stop == 0)
			ft_eat(philo);
		i++;
		if (*philo->stop == 0)
		{
			printf("Le philosophe %d dort\n", philo->number);
			usleep(*philo->time_to_sleep);
		}
		if (*philo->stop == 0)
			printf("Le philosophe %d pense\n", philo->number);
	}
	if (i == *philo->nbr_meat)
		*philo->stop = 1;
	philo->safe_stop = 1;
	printf("Le philosophe %d s'est desactive avec succes\n", philo->number);
}

void	active_mutex(t_philosopher *philo)
{
	if (philo->number % 2 == 0)
	{
		printf("active mutex\n");
		pthread_mutex_lock(philo->one);
	}
	else
		pthread_mutex_lock(philo->two);
	if (philo->number % 2 == 0) 
		pthread_mutex_lock(philo->two);
	else
		pthread_mutex_lock(philo->one);
}

void	desactive_mutex(t_philosopher *philo)
{
	if (philo->number % 2 == 0)
		pthread_mutex_unlock(philo->one);
	else
		pthread_mutex_unlock(philo->two);
	if (philo->number % 2 == 0)
		pthread_mutex_unlock(philo->two);
	else
		pthread_mutex_unlock(philo->one);
}

void	ft_eat(t_philosopher *philo)
{
	if (*philo->stop == 0)
	{
		philo->ms = get_time();
		philo->is_eating = 1;
		active_mutex(philo);
		if (philo->is_dead == 0)
			printf("le philosophe %d mange\n", philo->number);
		usleep(*philo->time_to_eat);
		philo->is_eating = 0;
		philo->ms = 0;
		desactive_mutex(philo);
	}

}
