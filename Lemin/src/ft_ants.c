/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:25:38 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:36:31 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_error(void)
{
	write(1, "ERROR\n", 7);
	exit(0);
}

int				ft_listroom(char **room_list, char *room)
{
	while (*room_list)
	{
		if (ft_strcmp(*room_list, room) == 0)
			return (1);
		room_list++;
	}
	return (0);
}

char			*second_ant(char **room_list, t_lem *lem)
{
	t_ant *lst;

	lst = lem->head_ants;
	while (lst)
	{
		if (!lst->begin)
		{
			if (!ft_listroom(room_list, *(lst->way + 1)))
			{
				lst->begin = 1;
				lst->name = ft_itoa(lem->ind_ant);
				lem->ind_ant++;
				return (*(lst->way + 1));
			}
		}
		lst = lst->next;
	}
	return (NULL);
}

char			*first_ant(t_lem *lem)
{
	t_ant *lst;

	lst = lem->head_ants;
	while (lst)
	{
		if (!lst->begin)
		{
			lst->begin = 1;
			lst->name = ft_itoa(lem->ind_ant);
			lem->ind_ant++;
			return (*(lst->way + 1));
		}
		lst = lst->next;
	}
	return (NULL);
}
