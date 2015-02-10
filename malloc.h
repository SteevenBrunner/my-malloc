/*
** malloc.h for malloc.h in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 14:40:50 2015 Steeven Brunner
** Last update Tue Feb 10 17:32:00 2015 Steeven Brunner
*/

#ifndef MALLOC_H_
# define MALLOC_H_

typedef	struct	block
{
  size_t	size;
  int		bool_free;
  struct block	*next;
  char		calc[1];
}		t_block;

void	*malloc(size_t size);
void	free(void *ptr);

extern t_block	*g_root;

#define BLOCK_SIZE sizeof(t_block)

#endif /* !MALLOC_H_ */
