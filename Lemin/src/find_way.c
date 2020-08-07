/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:21:07 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:45:34 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_find_way2(t_lem *lem, t_room **begin, int *f)
{
	ft_roomdouble(lem);
	free_stack(lem);
	ft_roomstack((*begin)->name, lem);
	(*begin) = search_copyroom(lem->start_char, &lem);
	(*begin)->flag_visit = 1;
	(*begin)->level = 1;
	ft_copybfs(lem);
	if (!(ft_short_ways2(lem)))
		*f = 0;
	ft_visited(lem);
}

void			ft_find_way3(t_lem *lem, t_room **begin, int *f)
{
	lem->count_ways = 0;
	lem->flag_cross = 0;
	free_arr_room2(lem);
	ft_deletecros(lem);
	arr_room2(lem);
	free_stack(lem);
	ft_roomstack((*begin)->name, lem);
	*f = 1;
	(*begin)->flag_visit = 1;
	(*begin)->level = 1;
	free_ways(lem);
	lem->index_ways--;
	ft_copybfs(lem);
	if (!(ft_short_ways2(lem)))
		*f = 0;
	ft_visited(lem);
}

void			ft_find_way4(t_lem *lem, int *f, t_room **begin)
{
	*f = 1;
	lem->lenght_ways = ft_memalloc(sizeof(int) * lem->num_room);
	lem->lenght_ways_j = lem->lenght_ways;
	lenght_forway(lem);
	lem->stack_room = ft_memalloc(sizeof(char*) * (*lem).num_room * 2);
	(*begin) = find_nameroom(&lem, lem->start_char);
	(*begin)->flag_visit = 1;
	(*begin)->level = 1;
	ft_roomstack((*begin)->name, lem);
	ft_bfs(lem);
	lem->short_way = ft_strdup(ft_short_ways(lem));
	arr_room2(lem);
}

void			search_way(t_lem *lem)
{
	int		f;
	t_room	*begin;

	ft_find_way4(lem, &f, &begin);
	while (f)
		ft_find_way2(lem, &begin, &f);
	ways_comeback(lem);
	new_count1(lem);
	while (lem->flag_cross)
	{
		if (find_waycross(lem))
		{
			ft_find_way3(lem, &begin, &f);
			while (f)
				ft_find_way2(lem, &begin, &f);
			ways_comeback(lem);
			new_count1(lem);
		}
		else
			return ;
	}
	ft_ways_back(lem);
	ft_sorting_ways(lem);
	log_ant(lem);
}
