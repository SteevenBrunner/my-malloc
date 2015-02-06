/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Fri Feb  6 11:31:41 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h> // brk / sbrk
#include <stdio.h>
//#include <stdlib.h>		//include malloc / free / realloc

#include "malloc.h"

// sbrk(X) pour allouer plus
// sbrk(0) pour connaitre la limite actuellement alouée (break)

void		*malloc(size_t size)
{
  t_block	*block;

  block = sbrk(0);
  printf("old_break = %x\n", block);
  if (sbrk(BLOCK_SIZE) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  printf("BLOCK_SIZE = %d\n", BLOCK_SIZE);
  printf("new_break = %x\n", sbrk(0));
  return (block);
}

/*t_block		find_block(t_block *last, size_t size)
{
  t_block	b = base;
  while (b && !(b->free && b->size >= size)) 
    {
      *last = b;
      b = b->next;
    }
  return (b);
}

t_block		add_blocks(t_block my_block, size_t size) //extend_heap
{
  t_block	new_block;

  new_block = sbrk(0);
  if(sbrk(size + STRUCT_SIZE) == (void*) - 1)
    {
      printf("Error : sbrk() failed\n");
      return (NULL);
    }
  if (my_block)
    my_block->next = new_block;
  new_block->free = 0;
  return (new_block);
  }*/

void	create_tab(int	*tab)
{
  printf("tab[1] = [%d]\n", tab[1]);
}

int	main()
{
  /*int	*tab2;
  tab2 = malloc(3 * sizeof(int));
  tab2[0] = 3;
  tab2[1] = 4;
  tab2[2] = 5;

  printf("\n-------------\n\n");
  
  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 6;
  tab3[1] = 7;
  tab3[2] = 8;

  printf("\n-------------\n\n");
  
  create_tab(tab2);
  create_tab(tab3);*/
  printf("First step\n");
  malloc(7 * sizeof(int));
  printf("Second step\n");
}

  //brk()
  //sbrk()
  //getrlimit() pour checker les limites des ressources systèmes
