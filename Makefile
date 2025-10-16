# Makefile pour My_SH

CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
NAME = my_sh

SRC = src/main.c \
	  src/shell/shell_loop.c \
	  src/shell/shell_banner.c \
	  src/builtins/builtin.c \
	  src/env/env.c \
	  src/env/setenv.c \
	  src/env/unsetenv.c \
	  src/cd/my_cd.c \
	  src/error/error.c \
	  src/parser/parser.c \
	  src/exit/exit.c \
	  src/arguments/args.c \
	  src/utils/current_dir.c \

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