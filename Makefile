# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 23:24:06 by yoel-idr          #+#    #+#              #
#    Updated: 2023/03/08 20:09:56 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			 	:= cub3D

CC 					:= cc
RM					:= rm -f
SRCS 				:= srcs/
INCLUDES			:= includes/
HEADERS 			:= parser.h leet3d.h # add ur headers name here
HEADERS 			:= $(addprefix $(INCLUDES), $(HEADERS))

FLAGS				:= #-Wall -Wextra -Werror 
debug 				:= -fsanitize=address -g
XLIB				:= -lmlx -framework OpenGL -framework AppKit

RED    				:= \033[1;00m
GREEN  				:= \033[1;32m
YELLOW 				:= \033[1;33m
BLUE   				:= \033[0;34m
RESET  				:= \033[0m
COM_COLOR   		:= \033[0;34m
OBJ_COLOR   		:= \033[0;36m
OK_COLOR    		:= \033[0;32m
NO_COLOR    		:= \033[m

OK_STRING    		:= "[OK]"
COM_STRING  	    := "Compiling"
LIBT		 		:= "libtools"
LEET_3D				:= "leet3d"
DELETE       		:= "Deleting objects"



# add VAR FOR Ur SRCS FILES LIKE :

LEET3D_FILE         := leet3d.c

PARSER_FILES        :=  start/leet_events.c \
						parser/parser.c \
						parser/map_utils.c \
						parser/map_utils1.c \
						parser/map_utils2.c \

UTILS_FILES 		:= utils/g_utils.c \

FILES 				:=  $(LEET3D_FILE) \
						$(PARSER_FILES) \
						$(UTILS_FILES)  \

FILES 				:= $(addprefix $(SRCS), $(FILES)) 
OBJS 				:= $(FILES:%.c=%.o)

LIBTOOLS_PATH		:= 	libtools/
LIBTOOLS 			:= $(addprefix $(LIBTOOLS_PATH), libtools.a)






# rules
all 				: $(NAME)
						@printf "%b   %b" "$(GREEN) $(LEET_3D)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; 

$(NAME) 			:	$(LIBTOOLS) $(OBJS)
							@$(CC) $(debug) $(FLAGS) $(XLIB) -pthread $^ -o $@

$(LIBTOOLS)			: 	$(addprefix $(LIBTOOLS_PATH), libtools.h)
							@make -C  $(LIBTOOLS_PATH) all

.c.o		 		:	$(HEADERS)
							@printf "%-100.900b\r" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
							@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES) -I $(addprefix $(LIBTOOLS_PATH), libtools.h)

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