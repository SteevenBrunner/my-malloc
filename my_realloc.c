/*
** realloc.c for realloc.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Mon Feb  2 17:04:06 2015 Steeven Brunner
<<<<<<< HEAD:my_realloc.c
** Last update Sun Feb 15 21:00:49 2015 Steeven Brunner
=======
** Last update Thu Feb 12 16:44:45 2015 Thomas Decamp
>>>>>>> 4b17b1f40fa915013aa899e24646b9e7521a4f7f:realloc.c
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
