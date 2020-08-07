/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 20:01:31 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 03:21:45 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			new_arr_room2(t_lem *lem)
{
	int		i;
	t_room	*lst;

	i = 0;
	while (i < SIZE_ARR)
	{
		lst = &lem->arr_room2[i];
		ft_bzero(lst, sizeof(t_room*));
		lst->next_hash = NULL;
		i++;
	}
}

void			new_arr_room(t_lem *lem)
{
	int		i;
	t_room	*lst;

	i = 0;
	while (i < SIZE_ARR)
	{
		lst = &lem->arr_room[i];
		ft_bzero(lst, sizeof(t_room*));
		lst->next_hash = NULL;
		i++;
	}
}

void			initialize_lem(t_lem *lem)
{
	lem->num_room = 0;
	lem->count_ants = 0;
	lem->end = 0;
	lem->start = 0;
	lem->flag_cross = 0;
	lem->cross_ind = -1;
	lem->ways = NULL;
	lem->map = NULL;
	lem->found_way = 0;
	lem->all_visited = 0;
	lem->count_ways = 0;
	lem->log_ants = NULL;
	lem->ind_ant = 1;
	lem->no_stackcheck = 0;
	lem->starts = 0;
	lem->ends = 0;
	new_arr_room(lem);
	new_arr_room2(lem);
}

void			ft_print_map(t_lem *lem)
{
	ft_putstr(lem->map);
	write(1, "\n", 1);
	write(1, "\n", 1);
}

int				main(void)
{
	t_lem		lem;

	lem.fd = 0;
	lem.head_ants = NULL;
	lem.room_head = NULL;
	initialize_lem(&lem);
	valid(&lem);
	search_way(&lem);
	ft_print_map(&lem);
	ft_print_all(&lem);
	exit(0);
}
