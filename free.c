/*
** free.c for free.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:43 2015 Steeven Brunner
** Last update Mon Feb  9 10:15:20 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "malloc.h"

void		free(void *ptr)
{
  t_block	*block;
  
  printf("\n********************\n\n");
  printf("Je suis free\n");
  printf("ptr =   %p\n", ptr);
  printf("block = %p\n", block);
  if (ptr == block)
    {
      block->bool_free = 0;
      printf("The block is free\n");
    }
  while (ptr != block)
    {
      printf("block = %p\n", block);
      if (ptr == block)
	{
	  printf("FIND ? Oh yeah\n");
	}
      block = block->next;
    }
  printf("\n*********************\n\n");
}
