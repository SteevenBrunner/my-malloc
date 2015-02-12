/*
** realloc.c for realloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:04:06 2015 Steeven Brunner
** Last update Thu Feb 12 16:44:45 2015 Thomas Decamp
*/

#include <stdlib.h>
#include <unistd.h>

void	*realloc(void *ptr, size_t size)
{
  void	*copy;

  if ((copy = malloc(size * sizeof(ptr))) == NULL)
    {
      return (NULL);
    }
  copy = &ptr;
  free(ptr);
  return (copy);
}
