##
## Makefile for Makefile in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
## 
## Made by Steeven Brunner
## Login   <brunne_s@epitech.net>
## 
## Started on  Mon Feb  2 16:06:06 2015 Steeven Brunner
## Last update Fri Feb 13 18:14:09 2015 Thomas Decamp
##

SRC =	malloc.c \
	free.c \
	calloc.c \
	realloc.c

NAME = libmy_malloc_$(HOSTTYPE).so

NAMESY = libmy_malloc.so

CC = cc

CFLAGS += -fPIC

OBJ = malloc.o

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -fPIC -shared $(OBJ)
	ln -s $(NAME) $(NAMESY)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(NAMESY)

re:	fclean all
