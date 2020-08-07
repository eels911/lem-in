/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:48:59 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:39:30 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_print_move(char *name, char *room)
{
	write(1, "L", 1);
	ft_putstr(name);
	write(1, "-", 1);
	ft_putstr(room);
	write(1, " ", 1);
}

void			ft_movement(t_lem **lem)
{
	t_ant		*lst;

	lst = (*lem)->head_ants;
	while (lst)
	{
		if (lst->begin && *(lst->way + 1))
		{
			ft_print_move(lst->name, *(lst->way + 1));
			lst->way++;
		}
		lst = lst->next;
	}
}
