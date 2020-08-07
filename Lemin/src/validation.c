/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 22:24:54 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 03:45:47 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			valid_map2(t_lem *lem, char **line)
{
	if (*line[0] == '#' && *line[1] != '#')
	{
		write_map("\n", lem);
		write_map(*line, lem);
		return ;
	}
	if (ft_strchr(*line, '-'))
		valid_connect(lem, *line);
	else
		valid_room(*line, lem);
}

void			check_comm(char **line, t_lem *lem)
{
	while ((*line[0] == '#' && *line[1] != '#'))
	{
		write_map("\n", lem);
		write_map(*line, lem);
		ft_strdel(line);
		get_next_line(lem->fd, line);
	}
}

void			ft_startend(char **line, t_lem *lem)
{
	if (ft_strcmp(*line, "##start") == 0)
	{
		lem->starts++;
		write_map("\n", lem);
		write_map(*line, lem);
		lem->start = 1;
		ft_strdel(line);
		get_next_line(lem->fd, line);
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		lem->ends++;
		write_map("\n", lem);
		write_map(*line, lem);
		lem->end = 1;
		ft_strdel(line);
		get_next_line(lem->fd, line);
	}
	if (*line[0] == '#' && *line[1] != '#')
		check_comm(line, lem);
}

void			valid_map(t_lem *lem)
{
	char	*line;

	while (get_next_line(lem->fd, &line) > 0)
	{
		lem->end = 0;
		lem->start = 0;
		if (line[0] == '\0')
			break ;
		if (line[0] == '#' && line[1] == '#')
		{
			ft_startend(&line, lem);
		}
		valid_map2(lem, &line);
		ft_strdel(&line);
	}
}

void			valid(t_lem *lem)
{
	num_ants(lem);
	valid_map(lem);
	if (lem->starts != 1 || lem->ends != 1)
		ft_error();
}
