/*
** malloc.h for malloc.h in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 14:40:50 2015 Steeven Brunner
** Last update Fri Feb  6 11:30:10 2015 Steeven Brunner
*/

typedef	struct	block
{
  size_t	size;
  int		free;
  struct block	*next;
}		t_block;

#define BLOCK_SIZE sizeof(t_block)
