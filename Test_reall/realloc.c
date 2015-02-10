/*
** realloc.c for realloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:04:06 2015 Steeven Brunner
** Last update Tue Feb 10 12:31:35 2015 Thomas Decamp
*/

#include <stdlib.h>
#include <unistd.h>

void	*my_realloc(void *ptr, size_t size)
{
  void	*copy;

  copy = malloc(size * sizeof(ptr));
  copy = &ptr;
  //free(ptr);
  return (copy);
}
