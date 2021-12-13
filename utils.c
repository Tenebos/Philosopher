/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:41:04 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/03 17:36:00 by aldamien         ###   ########.fr       */
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
