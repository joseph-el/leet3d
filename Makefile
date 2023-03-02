# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 23:24:06 by yoel-idr          #+#    #+#              #
#    Updated: 2023/03/02 23:40:27 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			 	:= cub3D

CC 					:= cc
RM					:= rm -f
SRCS 				:= srcs/
INCLUDES			:= includes/
HEADERS 			:= parser.h leet3d.h
HEADERS 			:= $(addprefix $(INCLUDES), $(HEADERS))

FLAGS				:= -Wall -Wextra -Werror 
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
DELETE       		:= "Deleting objects"

LEET3D_FILE         := leet3d.c

PARSER_FILES        :=  parser/parser.c \
						parser/map_utils.c
						parser/map_utils1.c
						parser/map_utils2.c

UTILS_FILES 		:= utils/g_utils.c

FILES 				:=  $(LEET3D_FILE)
						$(PARSER_FILES)
						$(UTILS_FILES)

FILES 				:= $(addprefix $(SRCS), $(FILES)) 
OBJS 				:= $(FILES:%.c=%.o)

LIBTOOLS_PATH		:= 	libtools/
LIBTOOLS 			:= $(addprefix $(LIBTOOLS_PATH), libtools.a)

# rules
all 				: $(NAME)
						@printf "%b   %b" "$(GREEN) <leet3d>" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; 

$(NAME) 			:	$(LIBTOOLS) $(OBJS)
							@$(CC) $(FLAGS) $^ -o $@

$(LIBTOOLS)			: 	$(addprefix $(LIBTOOLS_PATH), libtools.h)
							@make -C  $(LIBTOOLS_PATH) all

.c.o		 		:	$(HEADERS)
							@printf "%-100.900b\r" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
							@$(CC) $(FLAGS) $(XLIB) -c $< -o $@ -I $(INCLUDES) -I $(LIBTOOLS_PATH)

clean   			:	
							@printf "   %b %b  %b" "$(BLUE) $(DELETE)" "$(GREEN) <lee3d>" "$(OK_COLOR) $(OK_STRING) \n$(RESET)" 
							@$(RM) $(OBJS)
							@make -C $(LIBTOOLS_PATH) clean
fclean 				:  	clean
							@printf "\n\n   %b\t\t   %b\n" "$(BLUE) Deleting everything $(RESET)" "$(OK_COLOR)$(OK_STRING) $(RESET)"
							@make -C $(LIBTOOLS_PATH) fclean
							@$(RM) $(NAME)
re 					: 	fclean all

.PHONY 				: 	all clean fclean bonus re