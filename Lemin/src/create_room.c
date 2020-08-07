/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:01:20 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:38:23 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			create_room2(t_lem *lem, int i_hash,
char *line, t_room *lst)
{
	lst->flag_visit = 0;
	lst->connect = NULL;
	lst->count = 0;
	lst->has_connect = 0;
	lst->connect_ind = 0;
	lst->next_hash = NULL;
	ft_arr_room(lem, i_hash, lst);
	write_map("\n", lem);
	write_map(line, lem);
	(*lem).num_room++;
}

void			ft_createroom(char *line, t_lem *lem)
{
	t_room	*lst;
	int		ind;
	int		ind_hash;

	lst = ft_memalloc(sizeof(t_room));
	if ((ind = ft_tospace(line)))
	{
		ind_hash = hashi_calc(line);
		lst->name = ft_strnew(ind);
		ft_strncpy(lst->name, line, ind);
		create_room_3(lst, lem);
		create_room2(lem, ind_hash, line, lst);
	}
	else
	{
		all_free(lem);
		ft_error();
	}
	free(lst);
}

void			find_line(char *line, t_lem *lem)
{
	int		num;

	num = 0;
	while (*line)
	{
		if (*line == ' ')
		{
			line++;
			if (num > 2)
			{
				ft_error();
				all_free(lem);
			}
			num++;
			continue ;
		}
		line++;
	}
}

void			ft_name_of_room(char *line, t_lem *lem)
{
	find_line(line, lem);
	ft_createroom(line, lem);
}

void			valid_room(char *line, t_lem *lem)
{
	char	**mas;
	int		i;

	i = 0;
	mas = ft_strsplit(line, ' ');
	if (mas[3] != NULL || mas[2] == NULL || mas[1] == NULL)
		ft_error();
	if (line[0] == 'L' || line[0] == '#')
	{
		ft_error();
		all_free(lem);
	}
	ft_name_of_room(line, lem);
	while (mas[i])
	{
		ft_strdel(&mas[i]);
		i++;
	}
	free(mas);
}
