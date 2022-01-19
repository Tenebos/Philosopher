/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:39:50 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 12:00:51 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	analyze_philosopher(const t_philosopher *analyzed)
{
	printf("pid = %d\n", analyzed->pid);
	printf("number = %d\n", analyzed->number);
	printf("adress one = %p\n", analyzed->one);
	printf("adress two = %p\n", analyzed->two);
}

void	show_info(const	t_info *info)
{
	printf("nb of philo = %d\n", info->philo_nbr);
	printf("time_to_eat = %d\n", info->time_to_eat);
	printf("time to die = %d\n", info->time_to_die);
	printf("time to sleep = %d\n", info->time_to_sleep);
	printf("nbr of meat = %d\n", info->nbr_meat);
}
