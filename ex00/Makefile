NAME	=	MyFirstCannon

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

SRC_DIR	=	./
OBJ_DIR	=	obj/

# Source
FILES	=	main Fixed
HEADER	=	Fixed.hpp
INCLUDE	=	-I ./

SRCS	=	$(addprefix $(SRC_DIR), $(FILES:=.cpp))
OBJS	=	$(addprefix $(OBJ_DIR), $(FILES:=.o))

OBJF	=	.cache_exits

$(OBJF) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : %.cpp $(HEADER) Makefile | $(OBJF)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)$(NAME) Compiled!$(DEF_COLOR)"

all : $(NAME)

clean :
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJF)
	@echo "$(MAGENTA)$(NAME) objects cleaned !$(DEF_COLOR)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)$(NAME) cleaned !$(DEF_COLOR)"

re : fclean all
	@echo "$(GREEN)Cleaned and rebuilt !$(DEF_COLOR)"

.PHONY : all clean fclean re

# Color
DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
