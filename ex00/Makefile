NAME		= megaphone

CC			= g++
CFLAGS		+= -Wall -Werror -Wextra

SRC			= megaphone.cpp \

BLUE		= \033[38;5;105;1m
GREEN		= \033[1;32m
NO_COLOR    = \033[m

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(SRC)
	@printf "%b" "$(GREEN)Compiling: $(BLUE)$(NAME)\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(SRC)