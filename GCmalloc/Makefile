# **************************************************************************** #
#                                                                              #
#                                                       /\ ___ /\              #
#    Makefile                                          (  o   o  )             #
#                                                       \  >#<  /              #
#    By: alex <alexandre.loubeyres@gmail.com>           /       \              #
#                                                      /         \       ^     #
#    Created: 2015/06/18 15:49:05 by alex             |           |     //     #
#    Updated: 2015/06/18 15:56:35 by alex              \         /    //       #
#                                                       ///  ///   --          #
#                                                                              #
# **************************************************************************** #

NAME 	= libgcm.a

CC 	= gcc

SRC_C 	= src/

SRC_H 	= include/gc_malloc.h

SRC_O 	= $(SRC_C:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra -ansi -pedantic -I./include

$(NAME): $(SRC_0)
	@$(CC) $(CFLAGS) -c $(SRC_C)
	@ar rc $(NAME) $(SRC_O) $(SRC_H)
	@ranlib libmy.a
	@echo -e "\e[1;32mLibrary gcm OK"
	@cp $(NAME) ../

all: $(NAME)

clean:
	@rm -f $(SRC_O)

fclean: clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re: fclean all
