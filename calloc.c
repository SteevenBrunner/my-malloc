/*
** calloc.c for malloc in /home/decamp_t/rendu/PSU_2014_malloc/Test_reall
** 
** Made by Thomas Decamp
** Login   <decamp_t@epitech.net>
** 
** Started on  Wed Feb 11 15:05:18 2015 Thomas Decamp
** Last update Wed Feb 11 15:36:25 2015 Thomas Decamp
*/

#include <stdlib.h>
#include <unistd.h>

void	*calloc(size_t nmeb, size_t size)
{
  char	*ptr;
  int	i;

  i = 0;
  if ((ptr = malloc(nmeb * size)) == NULL)
    {
      return (NULL);
    }
  while (ptr[i])
    {
      ptr[i] = 0;
      i++;
    }
  return (ptr);
}
