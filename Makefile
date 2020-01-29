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
	  ./srcs/my_put_nbr.c \
	  ./srcs/my_putchar.c \
	  ./srcs/my_putstr.c \
	  ./srcs/my_revstr.c \
	  ./srcs/my_str_to_word_array.c \
	  ./srcs/my_strlen.c

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
