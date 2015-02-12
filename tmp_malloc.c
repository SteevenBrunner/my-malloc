/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
** Last update Thu Feb 12 12:37:05 2015 Steeven Brunner
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
      if (set_first_elem(size) == NULL)
	return NULL;
    }
  else
    {
      buff = g_root;
      while (buff->next || (buff->next && buff->bool_free == 1 &&
			    size <= buff->size))
	buff = buff->next;
      if (buff->bool_free == 1 && size <= buff->size)
	{
	  /*if (buff->size > size + BLOCK_SIZE)
	    {
	      //gerer les free opti
	      }*/
	  buff->size = size;
	  buff->bool_free = 0;
	  return ((char *)buff + BLOCK_SIZE);
	}
      else
	if (add_block(tmp, buff, size) == NULL)
	  return NULL;
      //retour de add_block à gérer
    }
  return (sbrk(0) - size);
}

void	*set_first_elem(size_t size)
{
  if ((g_root = sbrk(BLOCK_SIZE)) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  g_root->size = size;
  g_root->bool_free = 0;
  g_root->next = NULL;
}

void	*add_block(t_block *tmp, t_block *buff, size_t size)
{
  if ((tmp = sbrk(BLOCK_SIZE)) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  tmp->size = size;
  tmp->bool_free = 0;
  tmp->next = NULL;
  buff->next = tmp;
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
  printf("---------Malloc tab1---------\n\n");
  int	*tab;
  tab = malloc(1 * sizeof(int));
  tab[0] = 0;

  printf("\n---------Malloc tab2---------\n\n");
  int	*tab2;
  tab2 = malloc(6 * sizeof(int));
  tab2[0] = 1;
  tab2[1] = 2;
  tab2[2] = 33;
  tab2[3] = 34;
  tab2[4] = 35;
  tab2[5] = 36;

  printf("\n---------Free tab2---------\n\n");
  free(tab2);
  
  printf("\n---------Malloc tab3---------\n\n");
  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 94;
  tab3[1] = 95;
  tab3[2] = 96;
  

  printf("\n---------Malloc tab4---------\n\n");
  int	*tab4;
  tab4 = malloc(4 * sizeof(int));
  tab4[0] = 6;
  tab4[1] = 7;
  tab4[2] = 8;
  tab4[3] = 9;
  
  printf("\n              ----Final list----\n\n");
  
  t_block	*buff;
  
  buff = g_root;
  while (buff)
    {
      printf("size = %d, bool_free = %d\n", buff->size, buff->bool_free);
      buff = buff->next;
    }
  printf("\n");
}
