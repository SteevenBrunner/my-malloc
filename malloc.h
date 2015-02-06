/*
** malloc.h for malloc.h in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 14:40:50 2015 Steeven Brunner
** Last update Fri Feb  6 16:33:43 2015 Steeven Brunner
*/

#ifndef MALLOC_H_
# define MALLOC_H_

typedef	struct	block
{
  size_t	size;
  int		bool_free;
  struct block	*next;
}		t_block;

void	*malloc(size_t size);
void	free(void *ptr);
void	create_tab(int *tab);//à enlever

#define BLOCK_SIZE sizeof(t_block)

#endif /* !MALLOC_H_ */
