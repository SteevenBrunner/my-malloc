/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Mon Feb  9 16:28:45 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h> // brk / sbrk
#include <stdio.h>
//#include <stdlib.h>		//include malloc / free / realloc

#include "malloc.h"

// sbrk(X) pour allouer plus
// sbrk(0) pour connaitre la limite actuellement alouée (break)

t_block	*g_root = NULL; 

void		*malloc(size_t size)
{
  t_block	*tmp;
  t_block	*buff;
  
  if (g_root == NULL)
    {
      if ((g_root = sbrk(BLOCK_SIZE)) == (void*) - 1)
	{
	  printf("[Error] : sbrk failed\n");
	  return (NULL);
	}
      g_root->size = size;
      g_root->bool_free = 1;
      g_root->next = NULL;
    }  
  else
    {
      if ((tmp = sbrk(BLOCK_SIZE)) == (void*) - 1)
	{
	  printf("[Error] : sbrk failed\n");
	  return (NULL);
	}
      buff = g_root;
      while (buff->next)
	buff = buff->next;
      tmp->size = size;
      tmp->next = NULL;
      tmp->bool_free = 1;
      buff->next = tmp;
    }
  //checker si un espace est free pour remalloc dedans
   if (sbrk(size) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
   return (sbrk(0) - size);
}

void	toto()
{
  t_block	*toto;
  
  printf("toto 1\n");
  toto = g_root;
  printf("toto 2\n");
  printf("size = %d\n", toto->size);
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

int	main()
{
  int	*tab;
  tab = malloc(1 * sizeof(int));
  tab[0] = 0;

  int	*tab2;
  tab2 = malloc(2 * sizeof(int));
  tab2[0] = 1;
  tab2[1] = 2;

  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 3;
  tab3[1] = 4;
  tab3[2] = 5;

  int	*tab4;
  tab4 = malloc(4 * sizeof(int));
  tab4[0] = 6;
  tab4[1] = 7;
  tab4[2] = 8;
  tab4[3] = 9;

  printf("----YOLO----\n");
  printf("g_root->size = %d\n", g_root->size);
  printf("g_root->next->size = %d\n", g_root->next->size);
  printf("g_root->next->next->size = %d\n", g_root->next->next->size);
  /*  printf("\n---*****---\n");
  toto();
  printf("\n*************\n");*/
  //printf("\n-------------\n\n");

  /*  
  printf("\n-----1er free-----\n");
  free(tab);
  printf("\n-----2ème free-----\n");
  free(tab2);
  */
}

  //brk()
  //sbrk()
  //getrlimit() pour checker les limites des ressources systèmes
