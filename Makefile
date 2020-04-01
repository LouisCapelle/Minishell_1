##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makeifle
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= ./srcs/main.c \
	  ./srcs/lib/my_put_nbr.c \
	  ./srcs/lib/my_putchar.c \
	  ./srcs/lib/my_putstr.c \
	  ./srcs/lib/my_revstr.c \
	  ./srcs/lib/my_str_to_word_array.c \
	  ./srcs/lib/my_strstr.c \
	  ./srcs/lib/my_strcmp.c \
	  ./srcs/built_in.c \
	  ./srcs/shell.c \
	  ./srcs/check_errors.c \
	  ./srcs/parse_path/path.c \
	  ./srcs/parse_path/path_to_word_array.c \
	  ./srcs/lib/my_strlen.c \
	  ./srcs/get_next_line.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
