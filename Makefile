# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ingmar <ingmar@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/08 14:40:19 by ingmar        #+#    #+#                  #
#    Updated: 2021/05/09 13:44:35 by ingmar        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	= push_swap

PUSH_SRC	= push_swap/push_swap.c

PUSH_OBJ 	= $(PUSH_SRC:.c=.o)

CHECKER		= checker

CHECKER_SRC	= checker/checker.c

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

HELPERS_SRC	= helpers/helpers.c

HELPERS_OBJ	= $(HELPERS_SRC:.c=.o)

FLAGGOS		= -Wall -Wextra -Werror -o

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_OBJ) $(HELPERS_OBJ)
	@printf "\e[0;34m" "Compiling push_swap" "\e[0;35m\n"
	@$(CC) $(FLAGGOS) $(PUSH_SWAP) $(PUSH_SRC) $(HELPERS_SRC)

$(CHEKCER): $(CHECKER_OBJ) $(HELPERS_OBJ)
	@printf "\e[0;34m" "Compiling checker" "\e[0;35m\n"
	@$(CC) $(FLAGGOS) $(CHECKER) $(CHECKER_SRC) $(HELPERS_SRC)

re: fclean all

clean:
	@printf "\e[0;34m" "Removing objects" "\e[0;35m\n"
	@rm -f $(PUSH_OBJ) $(PUSH_SRC)

fclean: clean
	@printf "\e[0;34m" "Removing executables" "\e[0;35m\n"
	@rm -f $(PUSH_SWAP) $(CHECKER)