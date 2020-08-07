/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:08:11 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 03:42:30 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			write_map(char *line, t_lem *lem)
{
	char	*lst;

	if (lem->map == NULL)
		lem->map = ft_strdup(line);
	else
	{
		lst = ft_strjoin(lem->map, line);
		ft_strdel(&(lem->map));
		lem->map = lst;
	}
}

int				ants_end(t_lem *lem)
{
	t_ant *lst;

	lst = lem->head_ants;
	while (lst)
	{
		if (*(lst->way + 1))
			return (0);
		lst = lst->next;
	}
	return (1);
}
