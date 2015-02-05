/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Wed Feb  4 15:40:57 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h> // brk / sbrk
#include <stdio.h>
//#include <stdlib.h>		//include malloc / free / realloc

//#include "malloc.h"

// sbrk(X) pour allouer plus
// sbrk(0) pour connaitre la limite actuellement alouée (break)

void	*malloc(size_t size)
{
  void *p; 
  p = sbrk(0);
  printf("size = %d\n", size);
  //If sbrk fails , we return NULL
  printf("1 : sbk(0) = %x\n", sbrk(0));
  if (sbrk(size) == (void*) - 1)
    return  NULL;
  printf("2 : sbk(0) = %x\n", sbrk(0));
  return  p;
}

t_block	add_blocks(t_block my_block, size_t size)
{
  t_block	new_block;

  new_block = sbrk(0);
  if(sbrk(size + STRUCT_SIZE) == (void*) - 1)
    {
      printf("Error : sbrk\n");
      return (NULL);
    }
  if (my_block)
    my_block->next = new_block;
  new_block->free = 0;
  return (new_block);
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

  printf("\n-------------\n\n");
  
  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 6;
  tab3[1] = 7;
  tab3[2] = 8;

  printf("\n-------------\n\n");
  
  create_tab(tab2);
  create_tab(tab3);
  
}

  //brk()
  //sbrk()
  //getrlimit() pour checker les limites des ressources systèmes
