/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:36:28 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:45:37 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_connect_two(t_room *lst, t_room *in,
t_room *out, t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lst->connect_ind)
	{
		if (lst->connect[i])
		{
			if (lst->connect[i][0] == 'L')
			{
				i++;
				continue ;
			}
			change_connectroom(search_copyroom(
			lst->connect[i], &lem), lst->name, in->name);
			connect_copy(out, lst->connect[i]);
			i++;
		}
	}
}

t_room			*ft_outin(char **way, int i, t_lem *lem)
{
	t_room	*in;
	t_room	*out;
	char	*str;

	str = ft_strjoin(way[i], "in");
	in = room_copy(str, lem);
	in->is_double = 1;
	ft_strdel(&str);
	str = ft_strjoin(way[i], "out");
	out = room_copy(str, lem);
	out->is_double = 1;
	ft_strdel(&str);
	connect_copy(out, in->name);
	ft_connect_two(search_copyroom(
		way[i], &lem), in, out, lem);
	lem->out = out->name;
	return (in);
}

void			double_rooms_2(t_lem *lem, t_room *ant_in,
char **way, char *out_n)
{
	int		i;

	i = lem->i;
	if (i == lem->lenght_ways[0] - 2)
	{
		ant_in = ft_outin(way, i, lem);
		out_n = ft_strjoin(way[i - 1], "in");
		connect_copy(
		search_copyroom(out_n, &lem), lem->out);
		connect_copy(ant_in, way[i + 1]);
		ft_strdel(&out_n);
	}
	else
	{
		ft_strdel(&out_n);
		out_n = ft_strjoin(way[i - 1], "in");
		connect_copy(
		search_copyroom(out_n, &lem), way[i]);
		ft_strdel(&out_n);
	}
}

void			double_rooms_3(t_lem *lem, char **way)
{
	int			i;

	i = 1;
	while (i < lem->lenght_ways[lem->index_ways])
	{
		free_connect(way[i - 1], search_copyroom(way[i], &lem));
		free_connect(way[i], search_copyroom(way[i - 1], &lem));
		i++;
	}
}

void			ft_roomdouble(t_lem *lem)
{
	t_room	*inprev;
	t_room	*ant_in;
	char	**way;
	char	*out_n;

	lem->i = 1;
	way = ft_strsplit(lem->ways[lem->index_ways], ' ');
	double_rooms_3(lem, way);
	inprev = search_copyroom(way[lem->i - 1], &lem);
	while (lem->i < lem->lenght_ways[lem->index_ways] - 2)
	{
		ant_in = ft_outin(way, lem->i, lem);
		if (lem->i > 1)
			connect_copy(inprev,
			ft_outin(way, lem->i + 1, lem)->name);
		else
			ft_outin(way, lem->i + 1, lem);
		out_n = ft_strjoin(way[lem->i + 1], "out");
		connect_copy(ant_in, out_n);
		ft_strdel(&out_n);
		inprev = ant_in;
		lem->i += 2;
	}
	double_rooms_2(lem, ant_in, way, out_n);
	free_lstroom(way);
}
