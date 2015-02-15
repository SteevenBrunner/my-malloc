/*
** free.c for free.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:43 2015 Steeven Brunner
** Last update Sun Feb 15 21:07:23 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "my_malloc.h"

void		free(void *ptr)
{
  t_block	*tmp;
  t_block	*buff;

  tmp = g_root;
  buff = g_root;
  while (tmp != NULL && (char *)tmp + BLOCK_SIZE != ptr)
    tmp = tmp->next;
  if ((char *)tmp + BLOCK_SIZE == ptr)
    {
      printf("free = 1\n");
      tmp->bool_free = 1;
    }
  if (tmp->next == NULL)
    {
      sbrk(-(BLOCK_SIZE + tmp->size));
      while (buff->next != tmp)
	buff = buff->next;
      buff->next = NULL;
    }
  //Le dernier élément est bien supprimé, le break recule.
}
