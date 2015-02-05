/*
** malloc.h for malloc.h in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 14:40:50 2015 Steeven Brunner
** Last update Wed Feb  4 11:22:07 2015 Steeven Brunner
*/

typedef	struct	block
{
  size_t	size;
  int		free;
  t_block	next;
}		t_block;

#define BLOCK_SIZE sizeof(struct s_block)
