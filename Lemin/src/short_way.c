/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 21:23:08 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:51:09 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char			*ft_short_ways(t_lem *lem)
{
	int		size_way;
	t_room	*lst;

	lst = find_nameroom(&lem, lem->end_char);
	lem->index_ways = 0;
	size_way = lst->level;
	if (!lem->ways)
		lem->ways = ft_memalloc(sizeof(char*) * (SIZE_WAY + 1));
	buff_check(lem, lem->index_ways);
	while (lst->start != 1)
	{
		room_way(lst->name, &lem->ways[lem->index_ways]);
		lem->lenght_ways[0]++;
		lst = level_lower(lst, lem);
		if (!lst)
			ft_error();
	}
	room_way(lst->name, &lem->ways[lem->index_ways]);
	lem->lenght_ways[0]++;
	lem->short_lenghtway = lem->lenght_ways[0];
	lem->count_ways++;
	return (lem->ways[lem->index_ways]);
}
