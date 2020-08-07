# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannette <mannette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 17:04:23 by rfrieda           #+#    #+#              #
#    Updated: 2020/06/08 13:28:41 by mannette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB_PATH = ./libft/
HEADER = ./includes/
LIB = ./libft/libft.a

SRC_DIR = src
OBJS_DIR = obj

SRC_ALL = lem_in.c create_room.c create_room2.c valid_ants.c valid_connect.c \
		valid_connect2.c ft_clean.c ft_clean2.c way_back.c way_back2.c find_way.c \
		short_way.c ft_bfs.c ft_bfs2.c new_stack.c ft_log_ants.c sort_way.c \
		get_level.c room_connect.c double_room.c return.c ft_log_ants2.c \
		ft_print.c ft_print2.c move.c ft_ants.c ft_hash.c validation.c \

SRC = $(addprefix $(SRC_DIR)/,$(SRC_ALL))
OBJS = $(addprefix $(OBJS_DIR)/,$(SRC_ALL:.c=.o))

.PHONY: all clean fclean re force norm

all: $(LIB) $(NAME)

$(LIB): force
	make -C $(LIB_PATH)

$(NAME): $(OBJS_DIR) $(OBJS)
	gcc -Wall -Werror -Wextra $(OBJS) -I $(HEADER) -L "libft/" -lft -o $@

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c ./includes/lemin.h
	gcc -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@

norm:
	norminette

clean:
	rm -rf $(OBJS)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re: fclean all