NAME		= claptrap

CC			= g++
CFLAGS		+= -Wall -Werror -Wextra -Wc++98-compat -Wpedantic
INC			= -I.

SRC			= main.cpp \
			  ClapTrap.class.cpp \
			  FragTrap.class.cpp \
			  ScavTrap.class.cpp \
			  NinjaTrap.class.cpp \
			  SuperTrap.class.cpp \

BLUE		= \033[38;5;105;1m
GREEN		= \033[1;32m
NO_COLOR    = \033[m

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(SRC)
	@printf "%b" "$(GREEN)Compiling: $(BLUE)$(NAME)\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(SRC) $(INC)

fclean:
	rm $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)
