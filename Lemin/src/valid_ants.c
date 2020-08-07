/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 20:48:40 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 03:42:04 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			valid_ants(char *line, t_lem *lem)
{
	int		f;

	f = 0;
	while (*line)
	{
		if (*line > '0' && *line <= '9')
			f = 1;
		if (*line < '0' || *line > '9')
		{
			ft_error();
			all_free(lem);
		}
		line++;
	}
}

void			num_ants(t_lem *lem)
{
	char		*line;

	line = NULL;
	if (!(get_next_line(lem->fd, &line)))
		ft_error();
	valid_ants(line, lem);
	lem->map = ft_strdup(line);
	lem->count_ants = ft_atoi(line);
	ft_strdel(&line);
	if (lem->count_ants < 1)
	{
		ft_error();
		all_free(lem);
	}
}
