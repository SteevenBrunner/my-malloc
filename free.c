/*
** free.c for free.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:43 2015 Steeven Brunner
** Last update Tue Feb 10 17:43:39 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "malloc.h"

void		free(void *ptr)
{
  t_block	*tmp;
  int		i = 0;

  tmp = g_root;
  printf("\n**********START FREE************\n\n");
 
  tmp = ptr - BLOCK_SIZE;
  tmp->bool_free = 1;
  
  printf("\n********END FREE**********\n\n");
}
