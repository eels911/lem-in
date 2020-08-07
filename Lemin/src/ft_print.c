/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:05:32 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:37:28 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			add_arr_room(char **lst_room, char *room, t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->num_room)
	{
		if (!lst_room[i])
		{
			lst_room[i] = ft_strdup(room);
			return ;
		}
		i++;
	}
}

void			start_ants(t_lem *lem)
{
	int		i;
	char	*room;
	char	**lst_room;

	lst_room = ft_memalloc(sizeof(char*) * lem->num_room);
	i = lem->count_ways;
	room = first_ant(lem);
	if (room)
		add_arr_room(lst_room, room, lem);
	while (--i)
	{
		room = second_ant(lst_room, lem);
		if (!room)
			break ;
		add_arr_room(lst_room, room, lem);
	}
	free_lstroom(lst_room);
}

void			add_ant_to_list(char *way, t_lem *lem)
{
	t_ant		*lst;
	char		**arr_way;

	arr_way = ft_strsplit(way, ' ');
	lst = (t_ant*)ft_memalloc(sizeof(t_ant));
	lst->way = arr_way;
	lst->head_way = lst->way;
	lst->begin = 0;
	lst->next = lem->head_ants;
	lem->head_ants = lst;
}

void			ft_ant_list(t_lem *lem)
{
	int		l;
	int		i;
	int		j;

	l = 0;
	j = 0;
	i = lem->count_ants;
	while (lem->log_ants[lem->logi_best][j] != 0)
	{
		while (i > 0 && l < lem->log_ants[lem->logi_best][j])
		{
			add_ant_to_list(lem->ways[j], lem);
			i--;
			l++;
		}
		l = 0;
		j++;
	}
}

void			ft_print_all(t_lem *lem)
{
	ft_ant_list(lem);
	while (!ants_end(lem))
	{
		start_ants(lem);
		ft_movement(&lem);
		write(1, "\n", 1);
	}
}
