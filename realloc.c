/*
** realloc.c for realloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:04:06 2015 Steeven Brunner
** Last update Wed Feb 11 15:05:44 2015 Thomas Decamp
*/

#include <stdlib.h>
#include <unistd.h>

void	*realloc(void *ptr, size_t size)
{
  void	*copy;

  copy = malloc(size * sizeof(ptr));
  copy = &ptr;
  free(ptr);
  return (copy);
}
