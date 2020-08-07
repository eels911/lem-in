/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_ants2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 23:52:30 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:43:21 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			ft_numtimes(int *log_ant, t_lem *lem)
{
	int		max;
	int		l;
	int		time;

	max = 0;
	time = 0;
	l = 0;
	while (log_ant[l])
	{
		time = log_ant[l] - 2 + lem->lenght_ways[l];
		if (time > max)
			max = time;
		l++;
	}
	return (max);
}

void		ft_other_log(int other_ant, int i, t_lem *lem)
{
	int		k;

	k = 0;
	while (other_ant--)
	{
		lem->log_ants[i - 1][k] += 1;
		k++;
	}
}

void		log_write(int ant_on_way, int i, t_lem *lem)
{
	int		j;

	j = 0;
	if (lem->log_ants == NULL)
		lem->log_ants = ft_memalloc(sizeof(int*) *
		(lem->count_ways) + 1);
	lem->log_ants[i - 1] = ft_memalloc(sizeof(int) *
	(lem->count_ways + 1));
	while (j < i)
	{
		lem->log_ants[i - 1][j] = ant_on_way;
		j++;
	}
}
