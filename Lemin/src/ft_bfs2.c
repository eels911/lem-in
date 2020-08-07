/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:20:33 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:40:38 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				ft_parent(t_room *parent_room, char *child_name)
{
	int		i;

	i = parent_room->connect_ind;
	while (i > 0)
	{
		if (ft_strcmp(parent_room->connect[i - 1], child_name) == 0)
			return (1);
		i--;
	}
	return (0);
}

void			ft_bfs2(int i, t_room **lst, t_room **lst2, t_lem *lem)
{
	if (!(find_nameroom(&lem,
	(*lst)->connect[i - 1])->flag_visit))
	{
		ft_roomstack((*lst)->connect[i - 1], lem);
		*lst2 = find_nameroom(&lem, (*lst)->connect[i - 1]);
		(*lst2)->flag_visit = 1;
		(*lst2)->level = (*lst)->level + 1;
	}
}

void			ft_bfs(t_lem *lem)
{
	int		i;
	t_room	*lst;
	t_room	*lst2;
	char	**str;

	str = lem->stack_room;
	while (*str)
	{
		lst = find_nameroom(&lem, *str);
		if (lst->has_connect)
		{
			i = lst->connect_ind;
			while (i != 0)
			{
				ft_bfs2(i, &lst, &lst2, lem);
				i--;
			}
		}
		str++;
	}
}

void			ft_copybfs2(int *link, t_lem *lem, t_room **lst, t_room **lst2)
{
	if (!(search_copyroom((*lst)->connect[*link - 1],
	&lem)->flag_visit))
	{
		ft_roomstack((*lst)->connect[*link - 1], lem);
		*lst2 = search_copyroom((*lst)->connect[*link - 1],
		&lem);
		(*lst2)->flag_visit = 1;
		(*lst2)->level = (*lst)->level + 1;
	}
}

void			ft_copybfs(t_lem *lem)
{
	char	**str;
	t_room	*lst;
	t_room	*lst2;
	int		link;

	str = lem->stack_room;
	while (*str)
	{
		lst = search_copyroom(*str, &lem);
		if (lst->has_connect)
		{
			link = lst->connect_ind;
			while (link != 0)
			{
				if (lst->connect[link - 1][0] == 'L')
				{
					link--;
					continue ;
				}
				ft_copybfs2(&link, lem, &lst, &lst2);
				link--;
			}
		}
		str++;
	}
}
