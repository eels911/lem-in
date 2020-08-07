/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:02:56 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:49:18 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			free_arr_room3(t_room *lst)
{
	connect_free(lst);
	ft_strdel(&lst->name);
	ft_bzero(lst, sizeof(t_room));
}

void			lenght_forway(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->lenght_ways[i])
		lem->lenght_ways = 0;
}

void			free_arr_room2(t_lem *lem)
{
	int		i;
	t_room	*lst;
	t_room	*lst_hash;

	i = 0;
	while (i < SIZE_ARR - 302)
	{
		lst = &lem->arr_room2[i];
		if (lst->name)
		{
			if (!lst->next_hash)
				free_arr_room3(lst);
			else
			{
				while (lst->next_hash)
				{
					lst_hash = lst->next_hash;
					free_arr_room3(lst);
					lst = lst_hash;
				}
			}
		}
		i++;
	}
}

void			ft_return2(t_lem *lem, char **array, char **str1, int *i)
{
	if (strstr(array[*i], "in"))
	{
		if (search_copyroom(array[*i], &lem)->is_double == 1)
			*str1 = ft_strjoin_free(*str1, ft_strsub(array[*i],
			0, ft_strlen(array[*i]) - 2), 1, 1);
	}
	else if (strstr(array[*i], "out"))
	{
		if (search_copyroom(array[*i], &lem)->is_double == 1)
			*str1 = ft_strjoin_free(*str1, ft_strsub(array[*i],
			0, ft_strlen(array[*i]) - 3), 1, 1);
	}
	else
		*str1 = ft_strjoin_free(*str1, array[*i], 1, 0);
	*str1 = ft_strjoin_free(*str1, " ", 1, 0);
}

void			free_stack(t_lem *lem)
{
	int		i;
	char	**str;

	i = 0;
	str = lem->stack_room;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
}
