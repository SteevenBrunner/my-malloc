/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Wed Feb 11 17:15:09 2015 Steeven Brunner
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
//#include <stdlib.h>		//include malloc / free / realloc
#include "malloc.h"

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
      printf("size = %d\n", size);
      g_root->size = size;
      g_root->bool_free = 0;
      g_root->next = NULL;
    }  
  else
    {
      buff = g_root;
      while (buff->next || (buff->next && buff->bool_free == 1 && size <= buff->size))
	buff = buff->next;
      if (buff->bool_free == 1 && size <= buff->size)
	{
	  printf("Utilisation d'un maillon free\n");
	  printf("size = %d\n", size);
	  buff->size = size;
	  buff->bool_free = 0;
	  return ((char *)buff + BLOCK_SIZE);
	  //return ();
	}
      /*else if ((tmp = sbrk(BLOCK_SIZE)) == (void*) - 1)
	{
	printf("[Error] : sbrk failed\n");
	return (NULL);
	}*/
      else
	{
	  tmp = sbrk(BLOCK_SIZE);
	  printf("size = %d\n", size);
	  tmp->size = size;
	  tmp->bool_free = 0;
	  tmp->next = NULL;
	  buff->next = tmp;
	}
    }
  if (sbrk(size) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  return (sbrk(0) - size);
}

int	main()
{
  // si g_root->free = 1, on la considère comme free et par conséquent utilisable.
  printf("---------Malloc tab1---------\n");
  int	*tab;
  tab = malloc(1 * sizeof(int));
  tab[0] = 0;

  printf("\n---------Malloc tab2---------\n");
  int	*tab2;
  tab2 = malloc(6 * sizeof(int));
  tab2[0] = 1;
  tab2[1] = 2;
  tab2[2] = 33;
  tab2[3] = 34;
  tab2[4] = 35;
  tab2[5] = 36;

  printf("\n---------Free tab2---------\n");
  free(tab2);
  
  printf("\n---------Malloc tab3---------\n");
  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  printf("1--After malloc3\n");
  tab3[0] = 94;
  printf("2--After malloc3\n");
  tab3[1] = 95;
  tab3[2] = 96;
  printf("3--After malloc3\n");  
  
  //return (0);

  printf("\n---------Malloc tab4---------\n");
  int	*tab4;
  tab4 = malloc(4 * sizeof(int));
  tab4[0] = 6;
  tab4[1] = 7;
  tab4[2] = 8;
  tab4[3] = 9;
  
  printf("                      ----Final list----\n\n");
  printf("size = %d, bool_free = %d\n", g_root->size, g_root->bool_free);
  printf("size = %d, bool_free = %d\n", g_root->next->size, g_root->next->bool_free);
  printf("size = %d, bool_free = %d\n", g_root->next->next->size, g_root->next->next->bool_free);
 printf("size = %d, bool_free = %d\n\n", g_root->next->next->next->size, g_root->next->next->next->bool_free);

 printf("TOTO\n");

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
