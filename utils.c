/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:41:04 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/13 17:16:50 by aldamien         ###   ########.fr       */
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
		nb * (-1);
	return(nb);
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
				return(-1);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_print(char *txt, int nb, pthread_mutex_t *t1, int stop)
{
	int	i;

	i = 0;
		while (txt[i])
			i++;
		pthread_mutex_lock(t1);
		if (stop == 0)
			printf("%ld : Philosopher %d %s\n", get_time(), nb, txt);
		pthread_mutex_unlock(t1);
}
