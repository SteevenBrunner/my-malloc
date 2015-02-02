##
## Makefile for Makefile in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
## 
## Made by Steeven Brunner
## Login   <brunne_s@epitech.net>
## 
## Started on  Mon Feb  2 16:06:06 2015 Steeven Brunner
## Last update Mon Feb  2 16:08:37 2015 Steeven Brunner
##

SRC = my_malloc.c

NAME = my_malloc

CC = gcc my_malloc.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
