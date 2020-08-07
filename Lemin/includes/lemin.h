/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 20:33:02 by rfrieda           #+#    #+#             */
/*   Updated: 2020/06/08 03:43:07 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <limits.h>
# include "../libft/libft.h"
# define SIZE_WAY 2
# define SIZE_CONNECT 2
# define SIZE_ARR 5000

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				flag_visit;
	char			**connect;
	int				has_connect;
	int				connect_ind;
	int				count;
	int				is_double;
	int				level;
	struct s_room	*next_hash;
}					t_room;

typedef	struct		s_ant
{
	char			*name;
	int				begin;
	char			**head_way;
	char			**way;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_lem
{
	int				i;
	int				fd;
	int				starts;
	int				ends;
	int				short_lenghtway;
	char			*map;
	int				start;
	int				end;
	char			*start_char;
	char			*end_char;
	int				num_room;
	char			**ways;
	int				count_ways;
	char			*short_way;
	int				found_way;
	char			**stack_room;
	int				flag_cross;
	char			*cross_room;
	int				cross_ind;
	char			*out;
	int				all_visited;
	int				**log_ants;
	int				*time_log;
	int				*lenght_ways_j;
	int				*lenght_ways;
	int				logi_best;
	int				ind_ant;
	int				count_ants;
	int				no_stackcheck;
	int				index_ways;
	t_ant			*head_ants;
	t_room			*room_head;
	t_room			arr_room[SIZE_ARR];
	t_room			arr_room2[SIZE_ARR];
}					t_lem;

/*
** validation
*/
void				valid(t_lem *lem);
void				valid_room(char *line, t_lem *lem);
void				valid_connect(t_lem *lem, char *line);
int					valid_existroom(char *name, t_lem *lem);

/*
** ants
*/
void				num_ants(t_lem *lem);
void				log_ant(t_lem *lem);
char				*first_ant(t_lem *lem);
char				*second_ant(char **room_list, t_lem *lem);
int					ants_end(t_lem *lem);

/*
** free
*/
void				free_lstroom(char **str);
void				all_free(t_lem *lem);
void				free_ways(t_lem *lem);
void				free_way_i(t_lem *lem, int k);
void				connect_free(t_room *lst);
void				free_connect(char *name, t_room *lst);
void				free_stack(t_lem *lem);
void				free_arr_room2(t_lem *lem);

void				write_map(char *line, t_lem *lem);
void				stack_new(char	*way, char	**stack, t_lem *lem);
void				ft_error();
int					ft_tospace(char *line);
void				create_room_3(t_room *lst, t_lem *lem);
t_room				*room_copy(char *line, t_lem *lem);
t_room				*create_copyroom(char *line, t_lem *lem);
int					hashi_calc(char *line);
void				ft_arr_room(t_lem *lem, int i_hash,
t_room	*lst_room);
t_room				*arr_room_write(t_lem *lem,
int i_hash, t_room *lst_room);
void				ft_ways_back(t_lem *lem);
void				ft_way_back(t_lem *lem, int ind);
void				ft_deletecros(t_lem *lem);
int					find_waycross(t_lem *lem);
void				new_count1(t_lem *lem);
void				ways_comeback(t_lem *lem);
void				ft_sorting_ways(t_lem *lem);
void				ft_visited(t_lem *lem);
t_room				*search_copyroom(char *name, t_lem **lem);
t_room				*find_nameroom(t_lem **lem, char *name);
t_room				*level_lower(t_room *room, t_lem *lem);
int					level_lower2(t_lem *lem);
void				change_connectroom(t_room *lst,
char *name, char *name_new);
void				arr_room2(t_lem *lem);
void				ft_roomdouble(t_lem *lem);
void				ft_return2(t_lem *lem, char **array,
char **str1, int *i);
void				lenght_forway(t_lem *lem);
void				search_way(t_lem *lem);
char				*ft_short_ways(t_lem *lem);
int					ft_short_ways2(t_lem *lem);
void				connect_copy(t_room *one, char *two);
void				buff_connect(t_room *room);
int					ft_hashind(char *line);
void				log_write(int ant_on_way, int i, t_lem *lem);
int					ft_numtimes(int *log_ant, t_lem *lem);
void				ft_other_log(int other_ant, int i, t_lem *lem);
void				room_way(char *name, char **way);
void				ft_roomstack(char *line, t_lem *lem);
int					arr_index(char **stack);
void				ft_bfs(t_lem *lem);
void				ft_copybfs(t_lem *lem);
void				buff_check(t_lem *lem, int count);
int					ft_parent(t_room *parent_room, char *child_name);
void				ft_movement(t_lem **lem);
void				ft_print_all(t_lem *lem);
void				write_map(char *line, t_lem *lem);

#endif
