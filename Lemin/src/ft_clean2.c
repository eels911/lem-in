/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:35:10 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:29:24 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			connect_free(t_room *lst)
{
	while (lst->connect_ind != 0)
	{
		ft_strdel(&(lst->connect[lst->connect_ind - 1]));
		lst->connect_ind--;
	}
	free(lst->connect);
}

void			free_way_ant(char **way)
{
	int i;

	i = 0;
	while (way[i])
	{
		ft_strdel(&way[i]);
		i++;
	}
	free(way);
}

void			ft_freeants(t_lem *lem)
{
	int		i;
	t_ant	*lst;

	lst = lem->head_ants;
	i = 0;
	while (lem->head_ants)
	{
		lst = lem->head_ants;
		ft_strdel(&(lem->head_ants->name));
		free_way_ant(lst->head_way);
		lem->head_ants = lst->next;
		free(lst);
	}
}

void			log_free2(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->count_ways)
	{
		free(lem->log_ants[i]);
		i++;
	}
	free(lem->log_ants);
}

void			log_free(t_lem *lem)
{
	free(lem->time_log);
	free(lem->lenght_ways);
	log_free2(lem);
}
