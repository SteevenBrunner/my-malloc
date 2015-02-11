/*
** free.c for free.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:43 2015 Steeven Brunner
** Last update Wed Feb 11 15:39:49 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "malloc.h"

void		free(void *ptr)
{
  t_block	*tmp;

  tmp = g_root;
  tmp = ptr - BLOCK_SIZE;
  printf("tmp->size = %d\n", tmp->size);
  tmp->bool_free = 1;
}
