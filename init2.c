/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:20:44 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/19 14:28:14 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Philosophers.h"

void	create_fork(t_info *info, int nb)
{
	int	i;

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

void	create_fork_one(t_info *info)
{
	info->forks[0] = init_mutex();
	info->conclave[0].one = &info->forks[0];
	info->forks[1] = init_mutex();
	info->conclave[0].two = &info->forks[1];
}
