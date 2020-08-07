/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:36:18 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:29:10 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			free_way_i(t_lem *lem, int k)
{
	int		i;

	i = 0;
	while (i < k)
	{
		ft_strdel(&(lem->ways[i]));
		i++;
	}
	free(lem->ways);
}

void			free_ways(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->ways[i])
	{
		ft_strdel(&(lem->ways[i]));
		lem->lenght_ways[i] = 0;
		i++;
	}
	lem->index_ways = 0;
}

void			ft_free_room2(t_room *lst)
{
	t_room	*lst2;

	lst2 = lst->next_hash;
	if (lst->has_connect)
		connect_free(lst);
	ft_strdel(&(lst->name));
	free(lst);
	lst = lst2;
}

void			ft_free_room(t_lem *lem)
{
	t_room	*lst;
	int		i;

	i = 0;
	while (i < SIZE_ARR)
	{
		lst = &lem->arr_room[i];
		while (lst)
		{
			if (lst->next_hash)
				ft_free_room2(lst);
			else
			{
				if (lst->has_connect)
					connect_free(lst);
				ft_strdel(&(lst->name));
				free(lst);
				break ;
			}
		}
	}
}

void			all_free(t_lem *lem)
{
	ft_strdel(&(lem->map));
	free_ways(lem);
	ft_free_room(lem);
}
