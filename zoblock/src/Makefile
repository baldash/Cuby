##
## Makefile for zoblock in /home/sylvain/Documents/projets/perso/zoblock
## 
## Made by Sylvain Chaugny
## Login   <sylvain@epitech.net>
## 
## Started on  Fri Sep 23 20:43:35 2016 Sylvain Chaugny
## Last update Wed Feb  1 15:40:57 2017 Sylvain Chaugny
##

CC		=	gcc

CFLAGS		+=	-Wall -Wextra

CFLAGS		+=	-lncurses

DEBUG		?=	0

FSANITIZE	?=	0

ifeq ($(DEBUG), 1)
CFLAGS		+=	-g -ggdb3
endif

ifneq ($(FSANITIZE), 0)
CFLAGS		+=	-fsanitize=$(FSANITIZE)
endif

NAME		=	zobdisp

RM		=	rm -f

SRC		+=	zobdisp.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@
