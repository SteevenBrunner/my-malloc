/*
** malloc.h for malloc.h in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 14:40:50 2015 Steeven Brunner
** Last update Thu Feb 12 10:36:08 2015 Thomas Decamp
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
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t nmeb, size_t size);

extern t_block	*g_root;

#define BLOCK_SIZE sizeof(t_block)

#endif /* !MALLOC_H_ */
