NAME := cub3D

PARSING := ./srcs/map_utils.c ./srcs/map_utils1.c ./srcs/map_utils2.c ./srcs/parser.c ./srcs/g_utils.c ./srcs/leet3d.c
LIBTOOLS := ./libtools/libtools.a

FLAGS := -Wall -Wextra -Werror #-fsanitize=address -g

all : $(PARSING)
	@printf "<|cub3D|>\n"
	@gcc $(FLAGS) $(PARSING) $(LIBTOOLS) -o $(NAME)

lib :
	@make -C libtools re
