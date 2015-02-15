/*
** show_alloc_mem.c for show_alloc_mem.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:07:17 2015 Steeven Brunner
** Last update Sun Feb 15 21:21:10 2015 Steeven Brunner
*/

#include <stdio.h>

#include "malloc.h"

void	show_alloc_mem()
{
  t_block       *buff;

  buff = g_root;
  printf("break : %p\n", sbrk(0));
  while (buff)
    {
      printf("%p - %p : %d octets\n", ((char *)buff + BLOCK_SIZE), ((char *)buff + BLOCK_SIZE + buff->size), buff->size); 
      buff = buff->next;
    }
}
