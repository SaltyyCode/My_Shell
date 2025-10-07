# Makefile pour My_SH

CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
NAME = my_sh

SRC = src/main.c \
	  src/shell/shell_loop.c \
	  src/builtins/builtin.c \
	  src/env/env.c \
	  src/parser/parser.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re