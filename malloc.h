/*
** malloc.h for malloc in /home/decamp_t/rendu/PSU_2014_malloc
** Made by Thomas Decamp
** Login   <decamp_t@epitech.net>
** Started on  Fri Feb 13 14:07:25 2015 Thomas Decamp
** Last update Fri Feb 13 14:08:20 2015 Thomas Decamp
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
void	show_alloc_mem();
//void	*realloc(void *ptr, size_t size);
//void	*calloc(size_t nmeb, size_t size);

extern t_block	*g_root;

#define BLOCK_SIZE sizeof(t_block)

#endif /* !MALLOC_H_ */
