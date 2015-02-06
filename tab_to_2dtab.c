/*res
** tab_to_2dtab.c for tab_to_2dtab.c in /home/brunne_s/rendu/piscine_cpp_d02m/ex02
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Thu Jan  8 10:32:29 2015 Steeven Brunner
** Last update Thu Jan  8 11:30:02 2015 Steeven Brunner
*/

#include <stdlib.h>
#include <stdio.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	i;
  int	j;
  int	count;

  i = 0;
  count = 0;
  *res = malloc(length * sizeof(int*));
  while (i < length)
    {
      (*res)[i] = malloc(width * sizeof(int)); 
      i++;
    }
  i = 0;
  while (i < length)
    {
      j = 0;
      while (j < width)
	{
	  (*res)[i][j] = tab[count];
	  j++;
	  count++;
	}
      i++;
    }
}
