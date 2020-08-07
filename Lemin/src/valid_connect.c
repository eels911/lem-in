/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 18:47:07 by mannette          #+#    #+#             */
/*   Updated: 2020/06/08 02:32:47 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			room_link(char *one,
char *two, t_lem *lem)
{
	t_room		*lst;

	lst = find_nameroom(&lem, one);
	lst->has_connect = 1;
	if (lst->connect == NULL)
		lst->connect = ft_memalloc((sizeof(char*) * (SIZE_CONNECT + 1)));
	buff_connect(lst);
	lst->connect[lst->connect_ind] = ft_strdup(two);
	lst->connect_ind++;
}

void			connect_write(char *one,
char *two, t_lem *lem)
{
	write_map("\n", lem);
	write_map(one, lem);
	write_map("-", lem);
	write_map(two, lem);
}

int				num_len_sec(char *line)
{
	int		j;

	j = 0;
	while (line[j])
		j++;
	return (j);
}

void			valid_conn2(char *line, char *two,
char *one, t_lem *lem)
{
	if (valid_existroom(two, lem))
	{
		room_link(one, two, lem);
		room_link(two, one, lem);
		connect_write(one, two, lem);
	}
	else
		ft_error();
	if (line[ft_strlen(one) + ft_strlen(two) + 1] != '\0')
		ft_error();
	ft_strdel(&one);
	ft_strdel(&two);
}

void			valid_connect(t_lem *lem, char *line)
{
	char	*first;
	char	*second;
	int		i_hash;

	i_hash = ft_hashind(line);
	first = ft_memalloc(i_hash + 1);
	ft_strncpy(first, line, i_hash);
	if (valid_existroom(first, lem))
	{
		second = ft_memalloc(num_len_sec(line +
		i_hash + 1) + 1);
		ft_strcpy(second, line + i_hash + 1);
		valid_conn2(line, second, first, lem);
	}
	else
		ft_error();
}
