/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_connect2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 21:48:58 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:32:49 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				valid_existroom(char *name, t_lem *lem)
{
	t_room			*lst2;
	int				i_hash;

	i_hash = hashi_calc(name);
	lst2 = &lem->arr_room[i_hash];
	while (lst2)
	{
		if (!lst2->name)
			return (0);
		if (ft_strcmp(name, lst2->name) == 0)
			return (1);
		if (lst2->next_hash)
			lst2 = lst2->next_hash;
		else
			break ;
	}
	return (0);
}

int				ft_hashind(char *line)
{
	int i_hash;

	i_hash = 0;
	while (line[i_hash])
	{
		if (line[i_hash] == '-')
			return (i_hash);
		i_hash++;
	}
	return (-1);
}

int				size_connec(char **connect)
{
	int j;

	j = 0;
	while (connect[j])
	{
		j++;
	}
	return (j);
}

void			buff_connect(t_room *room)
{
	int		i_connect;
	int		size_connect;
	int		i;
	char	**str;

	i_connect = room->connect_ind;
	i = 0;
	if (room->connect_ind % (SIZE_CONNECT) == 0 && room->connect_ind != 0)
	{
		size_connect = size_connec(room->connect);
		str = ft_memalloc(sizeof(char*) *
		((SIZE_CONNECT + size_connect) + 1));
		while (i < size_connect)
		{
			str[i] = ft_strdup(room->connect[i]);
			i++;
		}
		connect_free(room);
		room->connect = str;
		room->connect_ind = i_connect;
	}
}

void			connect_copy(t_room *one, char *two)
{
	one->has_connect = 1;
	if (one->connect == NULL)
		one->connect = ft_memalloc((sizeof(char*) *
		(SIZE_CONNECT + 1)));
	buff_connect(one);
	one->connect[one->connect_ind] = ft_strdup(two);
	one->connect_ind++;
}
