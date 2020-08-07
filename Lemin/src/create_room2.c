/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:37:14 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:38:25 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			free_lstroom(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

t_room			*create_copyroom(char *line, t_lem *lem)
{
	int		i_hash;
	t_room	*lst;
	t_room	*lst2;
	t_room	*lst_room;

	lst_room = find_nameroom(&lem, line);
	lst = ft_memalloc(sizeof(t_room));
	i_hash = hashi_calc(line);
	lst->name = ft_strdup(line);
	lst->end = 0;
	lst->start = 0;
	lst->flag_visit = 0;
	lst->count = lst_room->count;
	lst->connect_ind = lst_room->connect_ind;
	lst->has_connect = lst_room->has_connect;
	lst->level = 0;
	lst->next_hash = NULL;
	lst2 = arr_room_write(lem, i_hash, lst);
	free(lst);
	return (lst2);
}

t_room			*room_copy(char *line, t_lem *lem)
{
	int		i_hash;
	t_room	*lst;
	t_room	*lst2;

	lst = ft_memalloc(sizeof(t_room));
	i_hash = hashi_calc(line);
	lst->name = ft_strdup(line);
	lst->end = 0;
	lst->start = 0;
	lst->flag_visit = 0;
	lst->count = lem->arr_room[i_hash].count;
	lst->connect_ind = lem->arr_room[i_hash].connect_ind;
	lst->has_connect = lem->arr_room[i_hash].has_connect;
	lst->level = 0;
	lst->next_hash = NULL;
	lst2 = arr_room_write(lem, i_hash, lst);
	free(lst);
	return (lst2);
}

void			create_room_3(t_room *lst, t_lem *lem)
{
	if (valid_existroom(lst->name, lem) == 1)
		ft_error();
	if (lem->start)
	{
		lst->start = 1;
		lem->start_char = ft_strdup(lst->name);
	}
	if (lem->end)
	{
		lst->end = 1;
		lem->end_char = ft_strdup(lst->name);
	}
}

int				ft_tospace(char *line)
{
	int		i;

	i = 0;
	while (line)
	{
		if (line[i] == ' ')
			return (i);
		i++;
	}
	return (-1);
}
