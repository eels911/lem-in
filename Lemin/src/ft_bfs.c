/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:43:45 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:40:33 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				arr_index(char **stack)
{
	int		i;

	i = 0;
	while (stack[i] != '\0')
		i++;
	return (i);
}

void			room_way(char *name, char **way)
{
	char		*str;

	if (!(*way))
		*way = ft_strdup(name);
	else
	{
		str = ft_strjoin(*way, " ");
		ft_strdel(way);
		*way = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(*way, name);
		ft_strdel(*(&way));
		*way = str;
	}
}

void			ft_roomstack(char *line, t_lem *lem)
{
	int		arr_i_zero;

	if (!(*(lem->stack_room)))
		*lem->stack_room = ft_strdup(line);
	else
	{
		arr_i_zero = arr_index(lem->stack_room);
		lem->stack_room[arr_i_zero] = ft_strdup(line);
	}
}

t_room			*next_room(t_lem *lem)
{
	int		i;
	t_room	*lst;

	i = 1;
	while (i < 10000)
	{
		if (lem->stack_room[i - 1])
		{
			lst = find_nameroom(&lem, lem->stack_room[i - 1]);
			if (!lst->flag_visit)
			{
				if (!(lst->end))
					return (lst);
			}
		}
		i++;
	}
	return (NULL);
}

void			buff_check(t_lem *lem, int num)
{
	int		i;
	char	**str;

	i = 0;
	if (num % SIZE_WAY == 0 && num != 0)
	{
		str = ft_memalloc(sizeof(char*) * ((num + 2) + 1));
		while (i < num)
		{
			str[i] = ft_strdup(lem->ways[i]);
			i++;
		}
		free_way_i(lem, num);
		lem->ways = str;
	}
}
