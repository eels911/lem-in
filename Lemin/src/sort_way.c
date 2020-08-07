/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 21:22:32 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:46:41 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room			*find_nameroom(t_lem **lem, char *name)
{
	t_room		*ptr;
	int			hash_index;

	hash_index = hashi_calc(name);
	ptr = &(*lem)->arr_room[hash_index];
	while (ptr)
	{
		if (ft_strcmp(ptr->name, name) == 0)
			return (ptr);
		if (ptr->next_hash)
			ptr = ptr->next_hash;
		else
			break ;
	}
	return (0);
}

void			ft_visited(t_lem *lem)
{
	int		i;
	t_room	*lst;

	i = 0;
	while (i < SIZE_ARR - 302)
	{
		lst = &lem->arr_room2[i];
		while (lst)
		{
			lst->flag_visit = 0;
			if (lst->next_hash)
				lst = lst->next_hash;
			else
				break ;
		}
		i++;
	}
}

t_room			*search_copyroom(char *name, t_lem **lem)
{
	t_room		*lst;
	int			i_hash;

	i_hash = hashi_calc(name);
	lst = &(*lem)->arr_room2[i_hash];
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
			return (lst);
		if (lst->next_hash)
			lst = lst->next_hash;
		else
			break ;
	}
	return (0);
}

void			ft_sorting_ways(t_lem *lem)
{
	int		i;
	char	*lst;
	int		len;

	i = 0;
	while (i < lem->count_ways - 1)
	{
		if (lem->lenght_ways[i] > lem->lenght_ways[i + 1])
		{
			len = lem->lenght_ways[i];
			lem->lenght_ways[i] = lem->lenght_ways[i + 1];
			lem->lenght_ways[i + 1] = len;
			lst = ft_strdup(lem->ways[i]);
			ft_strdel(&(lem->ways[i]));
			lem->ways[i] = lem->ways[i + 1];
			lem->ways[i + 1] = lst;
			ft_sorting_ways(lem);
		}
		i++;
	}
}
