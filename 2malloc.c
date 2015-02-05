/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Tue Feb  3 18:14:21 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h> // brk / sbrk
#include <stdio.h>
//#include <stdlib.h>		//include malloc / free / realloc

#include "malloc.h"

t_block extend_heap(t_block last, size_t s)
{
  t_block b;
  b =sbrk(0);
  if(sbrk(BLOCK_SIZE + s) == (void*)-1)
    /* sbrk fails ,go to die */
    return (NULL);
  b->size = s;
  b->next = NULL;
  if (last)
    last->next = b;
  b->free = 0;
  return (b);
}


void	create_tab(int	*tab)
{
  printf("tab[1] = [%d]\n", tab[1]);
}

int	main()
{
  int	*tab2;
  tab2 = malloc(3 * sizeof(int));
  tab2[0] = 3;
  tab2[1] = 4;
  tab2[2] = 5;

  
  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 6;
  tab3[1] = 7;
  tab3[2] = 8;
  
  create_tab(tab2);
  create_tab(tab3);
  
}

  //brk()
  //sbrk()
  //getrlimit() pour checker les limites des ressources systèmes
