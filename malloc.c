/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Fri Feb  6 16:24:44 2015 Steeven Brunner
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
  printf("\n*********************\n\n");
  printf("Je suis malloc\n");
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
  block = block->next;
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
*/

void	create_tab(int	*tab)
{
  printf("tab[1] = [%d]\n", tab[1]);
}

int	main()
{
  int	*tab;
  tab = malloc(3 * sizeof(int));
  tab[0] = 0;
  tab[1] = 1;
  tab[2] = 2;

  int	*tab2;
  tab2 = malloc(4 * sizeof(int));
  tab2[0] = 3;
  tab2[1] = 4;
  tab2[2] = 5;
  tab2[3] = 6;

  int	*tab3;
  tab3 = malloc(1 * sizeof(int));
  tab3[0] = 7;

  int	*tab4;
  tab4 = malloc(1 * sizeof(int));
  tab4[0] = 8;

  printf("\n-------------\n\n");
  
  /*  printf("\n-----1er free-----\n");
  free(tab);
  printf("\n-----2ème free-----\n");
  free(tab2);*/

  //create_tab(tab3);
  
  //  t_block	*toto;

  // toto = malloc(7 * sizeof(int));
}

  //brk()
  //sbrk()
  //getrlimit() pour checker les limites des ressources systèmes
