/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:07:39 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:43:18 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			time_log(t_lem *lem)
{
	int		min;
	int		k;
	int		high_log;

	min = 0;
	k = 0;
	lem->time_log = ft_memalloc(sizeof(int) * lem->count_ways);
	while (k < lem->count_ways)
	{
		lem->time_log[k] = ft_numtimes(lem->log_ants[k], lem);
		if (min == 0)
			min = lem->time_log[k];
		if (lem->time_log[k] < min)
		{
			high_log = k;
			min = lem->time_log[k];
		}
		k++;
	}
	return (high_log);
}

void		free_log(t_lem *lem)
{
	int		i;

	i = 2;
	lem->log_ants[1] = 0;
	while (lem->log_ants[i])
	{
		free(lem->log_ants[i]);
		i++;
	}
}

void		log_ant2(t_lem *lem)
{
	free_log(lem);
	lem->log_ants[0] = &lem->count_ants;
	free_ways(lem);
	lem->ways[0] = lem->short_way;
	lem->logi_best = 0;
	ft_way_back(lem, 0);
}

void		log_ant(t_lem *lem)
{
	int		small;
	int		num_way;
	int		ant_on_way;
	int		other_ant;

	num_way = 1;
	while (num_way <= lem->count_ways)
	{
		ant_on_way = lem->count_ants / num_way;
		log_write(ant_on_way, num_way, lem);
		other_ant = lem->count_ants % num_way;
		ft_other_log(other_ant, num_way, lem);
		num_way++;
	}
	lem->logi_best = time_log(lem);
	small = lem->count_ants - 2 + lem->short_lenghtway;
	if (lem->time_log[lem->logi_best] < small)
		return ;
	else
	{
		log_ant2(lem);
		return ;
	}
}
