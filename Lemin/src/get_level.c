/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:55:58 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 12:52:44 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				ft_short_ways2(t_lem *lem)
{
	t_room	*lst;

	lst = search_copyroom(lem->end_char, &lem);
	lem->index_ways++;
	if (!lem->ways)
		lem->ways = ft_memalloc(sizeof(char*) * (SIZE_WAY + 1));
	buff_check(lem, lem->index_ways);
	if (level_lower2(lem))
	{
		lem->count_ways++;
		return (1);
	}
	return (0);
}

t_room			*level_lower(t_room *room, t_lem *lem)
{
	int		i;
	t_room	*lst;

	i = 0;
	while (i < room->connect_ind)
	{
		lst = find_nameroom(&lem, room->connect[i]);
		if (lst->level == room->level - 1)
			return (lst);
		i++;
	}
	return (NULL);
}

void			low_level2(t_room **lst, int *lvl_curr,
char **name, t_lem *lem)
{
	if ((*lst)->level == *lvl_curr - 1)
	{
		if (ft_parent(*lst, *name) == 1)
		{
			room_way((*lst)->name, &lem->ways[lem->index_ways]);
			lem->lenght_ways[lem->index_ways]++;
			*name = (*lst)->name;
			*lvl_curr = (*lst)->level;
		}
	}
}

void			copy_level2(int *lvl_curr,
t_room **lst, char **name, t_lem *lem)
{
	*lvl_curr = (*lst)->level;
	*name = (*lst)->name;
	room_way((*lst)->name, &lem->ways[lem->index_ways]);
	lem->lenght_ways[lem->index_ways]++;
}

int				level_lower2(t_lem *lem)
{
	char	**str;
	int		i;
	int		lvl_curr;
	char	*name;
	t_room	*lst;

	i = 0;
	str = lem->stack_room;
	while (lem->stack_room[i])
		i++;
	i--;
	while (i >= 0 && ft_strcmp(lem->stack_room[i], lem->end_char) != 0)
		i--;
	if (i + 1 == 0)
		return (0);
	lst = search_copyroom(str[i], &lem);
	copy_level2(&lvl_curr, &lst, &name, lem);
	i--;
	while (i >= 0)
	{
		lst = search_copyroom(str[i], &lem);
		low_level2(&lst, &lvl_curr, &name, lem);
		i--;
	}
	return (1);
}
