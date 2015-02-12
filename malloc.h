/*
** malloc.h for malloc.h in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 14:40:50 2015 Steeven Brunner
<<<<<<< HEAD
** Last update Thu Feb 12 12:49:33 2015 Steeven Brunner
=======
** Last update Thu Feb 12 10:38:13 2015 Thomas Decamp
>>>>>>> ff7683ae966943f2e1e445e8d6597cd818844f0c
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
void	*add_block(t_block *tmp, t_block *buff, size_t size);
void	*set_first_elem(size_t size);
void	free(void *ptr);
<<<<<<< HEAD
void	show_alloc_mem();
=======
//void	*realloc(void *ptr, size_t size);
//void	*calloc(size_t nmeb, size_t size);
>>>>>>> ff7683ae966943f2e1e445e8d6597cd818844f0c

extern t_block	*g_root;

#define BLOCK_SIZE sizeof(t_block)

#endif /* !MALLOC_H_ */
