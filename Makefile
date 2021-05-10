# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ingmar <ingmar@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/08 14:40:19 by ingmar        #+#    #+#                  #
#    Updated: 2021/05/10 14:25:50 by ikole         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


#
## PUSH SWAP
#

PUSH_SWAP	= push_swap

PUSH_SRC	= pushSwap/push_swap.c

PUSH_OBJ 	= $(PUSH_SRC:.c=.o)

#
## CHECKER
#

CHECKER		= checker

CHECKER_SRC	= chonker/checker.c

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

#
## HELPERS
#

HELPERS_SRC	= helpers/helpers.c

HELPERS_OBJ	= $(HELPERS_SRC:.c=.o)

#
## LIBPS
#

LIBPS_SRC	= libps/stack.c libps/instructions.c

LIBPS_OBJ	= $(LIBPS_SRC:.c=.o)

#
## LIBPS
#

GNL_SRC		= getnextline/get_next_line.c

GNL_OBJ		= $(GNL_SRC:.c=.o)

FLAGGOS		= -Wall -Wextra -Werror -g -fsanitize=address -o


all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_OBJ) $(HELPERS_OBJ) $(LIBPS_OBJ)
	@printf "\e[0;34mCompiling push_swap\e[0;35m\n"
	@$(CC) $(FLAGGOS) $(PUSH_SWAP) $(PUSH_SRC) $(HELPERS_SRC) $(LIBPS_SRC)

$(CHECKER): $(CHECKER_OBJ) $(HELPERS_OBJ) $(LIBPS_OBJ) $(GNL_OBJ)
	@printf "\e[0;34mCompiling checker\e[0;35m\n"
	@$(CC) $(FLAGGOS) $(CHECKER) $(CHECKER_SRC) $(HELPERS_SRC) $(LIBPS_SRC) $(GNL_SRC)

re: fclean all

clean:
	@printf "\e[0;34mRemoving objects\e[0;35m\n"
	@rm -f $(PUSH_OBJ) $(PUSH_OBJ) $(CHECKER_OBJ) $(HELPERS_OBJ) $(LIBPS_OBJ)

fclean: clean
	@printf "\e[0;34mRemoving executables\e[0;35m\n"
	@rm -f $(PUSH_SWAP) $(CHECKER)
