/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 12:25:44 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 02:34:49 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			move_stack(int i, char **stack)
{
	while (stack[i + 1])
	{
		ft_strcpy(stack[i], stack[i + 1]);
		i++;
	}
}

void			delete_room(char *name, char **stack)
{
	int		i;

	i = 0;
	while (stack[i])
	{
		if (ft_strcmp(stack[i], name) == 0)
		{
			move_stack(i, stack);
			i = 0;
			continue ;
		}
		i++;
	}
}

void			free_arr_way(char **arr_way)
{
	int		i;

	i = 0;
	while (arr_way[i])
	{
		ft_strdel(&(arr_way[i]));
		i++;
	}
	ft_strdel(&(arr_way[i]));
	free(arr_way);
}

void			stack_new(char *way, char **stack, t_lem *lem)
{
	char	**arr_way;
	int		i;

	i = 0;
	arr_way = ft_strsplit(way, ' ');
	while (arr_way[i])
	{
		if (ft_strcmp(arr_way[i], lem->end_char) != 0 &&
		ft_strcmp(arr_way[i], lem->start_char) != 0)
			delete_room(arr_way[i], stack);
		i++;
	}
	free_arr_way(arr_way);
}
