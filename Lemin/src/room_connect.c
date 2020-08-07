/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:55:44 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:48:43 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			free_connect(char *name, t_room *lst)
{
	int		i;

	i = 0;
	while (i < lst->connect_ind)
	{
		if (ft_strcmp(name, lst->connect[i]) == 0)
		{
			ft_strdel(&lst->connect[i]);
			lst->connect[i] = ft_strdup("L");
			break ;
		}
		i++;
	}
}

void			ft_connect2(char ***aim, char **hash, int ind)
{
	int		i;

	i = 0;
	*aim = ft_memalloc(sizeof(char*) * ind);
	while (i < ind)
	{
		(*aim)[i] = ft_strdup(hash[i]);
		i++;
	}
}

void			ft_hash2(t_room *hash, t_lem *lem)
{
	t_room	*lst1;

	while (hash->next_hash)
	{
		hash = hash->next_hash;
		lst1 = create_copyroom(hash->name, lem);
		ft_connect2(&lst1->connect, hash->connect,
		hash->connect_ind);
	}
}

void			arr_room2(t_lem *lem)
{
	t_room	*lst;
	int		i;

	i = 0;
	while (i < SIZE_ARR)
	{
		lst = &lem->arr_room[i];
		if (lst->name)
		{
			create_copyroom(lst->name, lem);
			ft_connect2(&lem->arr_room2[i].connect,
			lst->connect, lst->connect_ind);
			if (lst->next_hash)
				ft_hash2(lst, lem);
		}
		i++;
	}
}

void			change_connectroom(t_room *lst,
char *name, char *name_new)
{
	int		i;

	i = 0;
	while (i < lst->connect_ind)
	{
		if (ft_strcmp(lst->connect[i], name) == 0)
		{
			ft_strdel(&lst->connect[i]);
			lst->connect[i] = ft_strdup(name_new);
			break ;
		}
		i++;
	}
}
