/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:41:13 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:49:56 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_way_back(t_lem *lem, int ind)
{
	char	**array;
	int		i;

	i = 1;
	array = ft_strsplit(lem->ways[ind], ' ');
	ft_strdel(&lem->ways[ind]);
	while (array[i])
		i++;
	i--;
	lem->lenght_ways[ind] = i;
	lem->ways[ind] = ft_strdup(array[i]);
	i--;
	while (i >= 0)
	{
		lem->ways[ind] = ft_strjoin_free(
			lem->ways[ind], " ", 1, 0);
		lem->ways[ind] = ft_strjoin_free(
			lem->ways[ind], array[i], 1, 0);
		i--;
	}
	free_lstroom(array);
}

void			ft_deletecros(t_lem *lem)
{
	char	**array;

	array = ft_strsplit(lem->cross_room, ' ');
	free_connect(array[0], find_nameroom(&lem, array[1]));
	free_connect(array[1], find_nameroom(&lem, array[0]));
	lem->flag_cross = 0;
	free_lstroom(array);
}

void			ft_ways_back(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->count_ways)
	{
		ft_way_back(lem, i);
		i++;
	}
}
