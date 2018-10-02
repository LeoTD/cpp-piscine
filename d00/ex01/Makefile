NAME		= Bills_PC

CC			= g++
CFLAGS		+= -Wall -Werror -Wextra
INC			= -I.

SRC			= Bills_PC.cpp \
			  Book.class.cpp \
			  Entry.class.cpp \

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