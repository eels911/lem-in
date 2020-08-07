/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_back2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 23:04:46 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:52:07 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				find_waycross(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->cross_ind)
	{
		if (ft_strstr(lem->ways[i], lem->cross_room))
			return (1);
		i++;
	}
	return (0);
}

char			*return_way(char *way, t_lem *lem)
{
	int		i;
	char	**array;
	char	*str;

	str = ft_strnew(0);
	i = 0;
	array = ft_strsplit(way, ' ');
	while (array[i])
	{
		ft_return2(lem, array, &str, &i);
		i++;
	}
	free_lstroom(array);
	return (str);
}

void			ways_comeback(t_lem *lem)
{
	int		i;
	char	*str;

	i = 0;
	while (i < lem->index_ways)
	{
		str = return_way(lem->ways[i], lem);
		ft_strdel(&lem->ways[i]);
		lem->ways[i] = str;
		i++;
	}
}

int				new_count(char *way, t_lem *lem)
{
	int		i;
	char	**array;
	t_room	*lst;

	i = 1;
	array = ft_strsplit(way, ' ');
	while (array[i + 1])
	{
		lst = search_copyroom(array[i], &lem);
		lst->count++;
		if (lst->count >= 2)
		{
			lem->cross_room = ft_strdup(array[i + 1]);
			lem->cross_room = ft_strjoin_free(lem->cross_room, " ", 1, 0);
			lem->cross_room = ft_strjoin_free(lem->cross_room,
			lst->name, 1, 0);
			free_lstroom(array);
			return (0);
		}
		i++;
	}
	free_lstroom(array);
	return (1);
}

void			new_count1(t_lem *lem)
{
	int		j;

	j = 0;
	while (j < lem->index_ways)
	{
		if (!new_count(lem->ways[j], lem))
		{
			lem->flag_cross = 1;
			lem->cross_ind = j;
			break ;
		}
		j++;
	}
}
