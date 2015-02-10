/*
** main_realloc.c for ammloc in /home/decamp_t/rendu/PSU_2014_malloc
** 
** Made by Thomas Decamp
** Login   <decamp_t@epitech.net>
** 
** Started on  Mon Feb  9 12:55:41 2015 Thomas Decamp
** Last update Mon Feb  9 16:23:50 2015 Thomas Decamp
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
  int	i;
  int	*tab;
  tab = malloc(3 * sizeof(int));
  tab[0] = 5;
  tab[1] = 1;
  tab[2] = 2;

  i = 0;

  while(tab[i])
    {
      printf("%d\n", tab[i]);
      i++;
    }

  my_realloc(tab, 4);

  i = 0;
  printf("\n--------------\n");

  tab[3] = 9;

  while(tab[i])
    {
      printf("%d\n", tab[i]);
      i++;
    }


  free(tab);
  printf("\n*************\n");
}
