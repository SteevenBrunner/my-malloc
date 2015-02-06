/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Fri Feb  6 15:10:30 2015 Steeven Brunner
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
  printf("old_break = %p\n", block);
  if (sbrk(BLOCK_SIZE) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  /*printf("BLOCK_SIZE = %d\n", BLOCK_SIZE);
    printf("new_break = %p\n", sbrk(0));*/
  // Ok le break est déplacé à la fin de la struct
  block->size = size;
  block->bool_free = 1;
  /* printf("\n---------------------\n\n");
  printf("block->size = %d\n", block->size);
  printf("block->bool_free = %d\n", block->bool_free);*/
  // Var initialisées
  // Déplacer le break de la size demandée
  if (sbrk(size) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  return (sbrk(0) - size);
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
  int	*tab;
  printf("sbrk(0) = %p\n", sbrk(0));
  tab = malloc(3 * sizeof(int));
  printf("sbrk(0) = %p\n", sbrk(0));
  tab[0] = 3;
  tab[1] = 4;
  tab[2] = 5;

  printf("\n-------------\n\n");
  
  /* int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 6;
  tab3[1] = 7;
  tab3[2] = 8;

  printf("\n-------------\n\n");*/
  
  create_tab(tab);
  //create_tab(tab3);
  
  //  t_block	*toto;

  // toto = malloc(7 * sizeof(int));
}

  //brk()
  //sbrk()
  //getrlimit() pour checker les limites des ressources systèmes
