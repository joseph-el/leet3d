# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 14:57:49 by yoel-idr          #+#    #+#              #
#    Updated: 2023/03/13 18:42:34 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d

CC 					:= cc
RM					:= rm -f
SRCS 				:= srcs/
INCLUDES			:= includes/
HEADERS 			:= parser.h leet3d.h raycasting.h
HEADERS 			:= $(addprefix $(INCLUDES), $(HEADERS))
FLAGS				:= -Wall -Wextra -Werror 
XLIB				:= -lmlx -framework OpenGL -framework AppKit

COM_COLOR   		:= \033[0;34m
OBJ_COLOR   		:= \033[0;36m
OK_COLOR    		:= \033[0;32m
NO_COLOR    		:= \033[m
OK_STRING    		:= "[OK]"
COM_STRING  	    := "Compiling"
LIBT		 		:= "libtools"
LEET_3D				:= "leet3d"
DELETE       		:= "Deleting objects"

LEET3D_FILE         := leet3d.c \

PARSER_FILES        :=  parser/parser.c \
						parser/map_utils.c \
						parser/map_utils1.c \
						parser/map_utils2.c \

EVENTS_FILES		:=  events/events.c \
						events/events_utils.c \
						events/events_utils1.c \
						events/events_utils2.c \
						events/button.c \

RAYCASTING_FILES	:=  raycasting/minimap.c \
						raycasting/minimap_utils.c \
						raycasting/_angle.c \
						raycasting/_direction.c \
						raycasting/has_wall_at.c \
						raycasting/horizontal_raycast.c \
						raycasting/moves.c \
						raycasting/raycasting.c \
						raycasting/render.c \
						raycasting/vertical_raycast.c \
						raycasting/wall_pixel.c \
						raycasting/wall_render.c \

UTILS				:=  utils/enemy.c \
						utils/enemy_utils.c \
						utils/initialize.c \
						utils/destroy.c \
						utils/error.c \
						utils/sound.c \

FILES				:=  $(PARSER_FILES) \
						$(LEET3D_FILE) \
						$(UTILS) \
						$(LEET3D_FILE) \
						$(EVENTS_FILES) \
						$(RAYCASTING_FILES) \

FILES 				:= $(addprefix $(SRCS), $(FILES)) 
OBJS 				:= $(FILES:%.c=%.o)

LIBTOOLS_PATH		:= 	libtools/
LIBTOOLS 			:= $(addprefix $(LIBTOOLS_PATH), libtools.a)

all 				: $(NAME)
						@printf "%b   %b" "$(GREEN) $(LEET_3D)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; 

$(NAME) 			:	$(LIBTOOLS) $(OBJS)
							@$(CC) $(debug) $(FLAGS) $(XLIB) -pthread $^ -o $@
$(LIBTOOLS)			: 	$(addprefix $(LIBTOOLS_PATH), libtools.h)
							@make -C  $(LIBTOOLS_PATH) all

.c.o		 		:	$(HEADERS)
							@printf "%-100.900b\r" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
							@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBTOOLS_PATH)
clean   			:	
							@printf "	   %b %b %b\t" "$(BLUE) $(DELETE)" "$(GREEN)       $(LIBT)" "$(OK_COLOR) $(OK_STRING) \n$(RESET)" 
							@printf "   %b %b  %b        " "$(BLUE) $(DELETE)" "$(GREEN)      $(LEET_3D)" "$(OK_COLOR)       $(OK_STRING) \n$(RESET)" 
							@$(RM) $(OBJS)
							@make -C $(LIBTOOLS_PATH) clean

fclean 				:  	clean
							@printf "%b\t\t   %b\n" "$(BLUE) Deleting everything $(RESET)" "$(OK_COLOR)         $(OK_STRING) $(RESET)"
							@make -C $(LIBTOOLS_PATH) fclean
							@$(RM) $(NAME)
re 					: 	fclean all

.PHONY 				: 	all clean fclean bonus re