# **************************************************************************** #
#                                                                              #
#                                                       /\ ___ /\              #
#    Makefile                                          (  o   o  )             #
#                                                       \  >#<  /              #
#    By: alex <alexandre.loubeyres@gmail.com>           /       \              #
#                                                      /         \       ^     #
#    Created: 2015/06/18 15:49:05 by alex             |           |     //     #
#    Updated: 2015/06/21 17:43:42 by alex              \         /    //       #
#                                                       ///  ///   --          #
#                                                                              #
# **************************************************************************** #

NAME 	= libgcm.a

CC 	= gcc

SRC 	= src/creat_gc_malloc.c \
	  src/free_gc_malloc.c \

OBJ 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra -ansi -pedantic -I./include

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "\e[1;32mLibrary gcm OK"
	@cp $(NAME) ../

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re: fclean all
