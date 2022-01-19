/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:55:15 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 11:58:39 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	enought(t_info *faustine)
{
	int	j;

	j = 0;
	while (j < faustine->philo_nbr)
	{
		if (faustine->conclave[j].enought_eat == 1)
			j++;
		else
			break ;
		if (j == faustine->philo_nbr)
			faustine->stop = 1;
	}
}
