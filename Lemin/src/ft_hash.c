/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:29:19 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:30:11 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room			*arr_room_write(t_lem *lem,
int i_hash, t_room *lst_room)
{
	t_room	*lst;

	lst = &lem->arr_room2[i_hash];
	if (!lst->name)
	{
		*lst = *lst_room;
		return (lst);
	}
	else
	{
		while (lst->next_hash)
		{
			lst = lst->next_hash;
			if (!lst->name)
			{
				*lst = *lst_room;
				return (lst);
			}
		}
		lst->next_hash = ft_memalloc(sizeof(t_room));
		*lst->next_hash = *lst_room;
		lst->next_hash->next_hash = NULL;
		return (lst->next_hash);
	}
}

void			ft_arr_room(t_lem *lem, int i_hash, t_room *lst_room)
{
	t_room	*lst;

	lst = &lem->arr_room[i_hash];
	if (!lst->name)
		*lst = *lst_room;
	else
	{
		while (lst->next_hash)
		{
			lst = lst->next_hash;
			if (!lst->name)
			{
				*lst = *lst_room;
				return ;
			}
		}
		lst->next_hash = ft_memalloc(sizeof(t_room));
		*lst->next_hash = *lst_room;
		lst->next_hash->next_hash = NULL;
	}
}

int				hashi_calc(char *line)
{
	int		sum;
	int		i;

	sum = 0;
	while (*line != ' ' && *line)
	{
		sum += *line;
		line++;
	}
	i = sum % SIZE_ARR;
	return (i);
}
