NAME		= logger

CXX			= g++
CXXFLAGS	+= -Wall -Werror -Wextra -std=c++98 -pedantic-errors
INC			= -I.

SRC			= main.cpp \
			  Logger.cpp \

BLUE		= \033[38;5;105;1m
GREEN		= \033[1;32m
NO_COLOR    = \033[m

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(SRC)
	@printf "%b" "$(GREEN)Compiling: $(BLUE)$(NAME)\n$(NO_COLOR)"
	@$(CXX) $(DEBUG) $(CXXFLAGS) -o $(NAME) $(SRC) $(INC)

fclean:
	rm $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)
