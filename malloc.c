/*
** malloc.c for malloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:03:00 2015 Steeven Brunner
<<<<<<< HEAD:my_malloc.c
** Last update Sun Feb 15 21:21:22 2015 Steeven Brunner
=======
** Last update Fri Feb 13 18:32:34 2015 Thomas Decamp
>>>>>>> 4b17b1f40fa915013aa899e24646b9e7521a4f7f:malloc.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

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
      printf("buff->bool_free = %d\n", buff->bool_free);
      printf("size %d <= buff->size %d\n", size, buff->size);
      if (buff->bool_free == 1 && size <= buff->size)
	{
	  //call split_free_block()
	  buff->size = size;
	  buff->bool_free = 0;
	  printf("(char *)buff + BLOCK_SIZE = %p\n", (char *)buff + BLOCK_SIZE);
	  return ((char *)buff + BLOCK_SIZE);
	}
      else
	if (add_block(tmp, buff, size) == NULL)
	  return NULL;
      //retour de add_block à gérer
    }
  printf("(sbrk(0) - size) = %p\n", (sbrk(0) - size));
  return (sbrk(0) - size);
}
/*
void	*split_free_block(t_block *tmp, t_block *buff, size_t size)
{
  printf("buff->size = %d\n", buff->size);
  printf("buff->size = %d\n", buff->size);
  if (buff->size > size + BLOCK_SIZE)
    {
      /*if ((tmp = sbrk(BLOCK_SIZE)) == (void*) - 1)
	{
	  printf("[Error] : sbrk failed\n");
	  return (NULL);
	  }
      printf("Split free block\n");
      tmp->size = size;
      tmp->bool_free = 0;
      tmp->next = NULL;
      buff->next = tmp;
    }
  return NULL;
}
*/

void	*set_first_elem(size_t size)
{
  if ((g_root = sbrk(BLOCK_SIZE + size)) == (void*) - 1)
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
  if ((tmp = sbrk(BLOCK_SIZE + size)) == (void*) - 1)
    {
      printf("[Error] : sbrk failed\n");
      return (NULL);
    }
  tmp->size = size;
  tmp->bool_free = 0;
  tmp->next = NULL;
  buff->next = tmp;
  return (sbrk(0) - size);
}
/*
int	main()
{
  // si g_root->free = 1, on la considère comme free et par conséquent utilisable.
  printf("---------Malloc tab1---------\n\n");
  int	*tab;
  tab = malloc(1 * sizeof(int));
  tab[0] = 0;

  printf("sbrk(0) tab = %p\n", sbrk(0));

  printf("\n---------Malloc tab2 = size = 16 * 4 = 64---------\n\n");
  int	*tab2;
  tab2 = malloc(16 * sizeof(int));
  tab2[0] = 0;
  tab2[1] = 1;
  tab2[2] = 2;
  tab2[3] = 3;
  tab2[4] = 4;
  tab2[5] = 5;
  tab2[6] = 6;
  tab2[7] = 7;
  tab2[8] = 8;
  tab2[9] = 9;
  tab2[10] = 10;
  tab2[11] = 11;
  tab2[12] = 12;
  tab2[13] = 13;
  tab2[14] = 14;
  tab2[15] = 15;

  printf("sbrk(0) tab2 = %p\n", sbrk(0));

  //free(tab2);

  printf("\n---------Malloc tab3---------\n\n");
  int	*tab3;
  tab3 = malloc(3 * sizeof(int));
  tab3[0] = 94;
  tab3[1] = 95;
  tab3[2] = 96;
  
  printf("sbrk(0) tab3 = %p\n", sbrk(0));

  printf("\n---------Free tab2---------\n\n");
  //printf("tab = %p\n", tab);
  free(tab2);

  printf("\n---------Malloc tab4---------\n\n");
  int	*tab4;
  tab4 = malloc(4 * sizeof(int));
  tab4[0] = 6;
  tab4[1] = 7;
  tab4[2] = 8;
  tab4[3] = 9;

  t_block	*buff;

  buff = g_root;

  while (buff != NULL)
    {
      printf("size = %d   ---   ", buff->size);
      printf("bool_free = %d\n", buff->bool_free);
      buff = buff->next;
    }
    printf("END OF PRINT\n");

  printf("sbrk(0) tab4 = %p\n", sbrk(0));

  //free(tab4);

  printf("\n              ----Show_alloc_mem()----\n\n");
  //  show_alloc_mem();
}
*/
