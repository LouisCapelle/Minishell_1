##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my_put_nbr.c \
	  ./lib/my_putchar.c \
	  ./lib/my_putstr.c \
	  ./lib/my_revstr.c \
	  ./lib/my_str_to_word_array.c \
	  ./lib/my_strcat.c \
	  ./lib/my_strcmp.c \
	  ./lib/my_strdup.c \
	  ./lib/my_strlen.c \
	  ./lib/my_strstr.c \
	  ./src/check/check_command.c \
	  ./src/check/check_access.c \
	  ./src/check/check_local.c \
	  ./src/core/minshell.c \
	  ./src/main.c \
	  ./src/free.c \
	  ./src/exec/exec_command.c \
	  ./src/exec/get_command.c \
	  ./src/exec/exec_local.c \
	  ./src/error/exec_error.c \
	  ./src/built_in/my_exit.c \
	  ./src/built_in/my_cd.c \
	  ./src/built_in/check_builtins.c \
	  ./src/built_in/my_setenv.c \
	  ./src/parsing/word_array_separator.c \
	  ./src/parsing/get_env_line.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
