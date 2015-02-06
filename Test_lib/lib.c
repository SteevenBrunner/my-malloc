/*
** lib.c for mallox in /home/decamp_t/rendu/PSU_2014_malloc
** 
** Made by Thomas Decamp
** Login   <decamp_t@epitech.net>
** 
** Started on  Fri Feb  6 13:16:56 2015 Thomas Decamp
** Last update Fri Feb  6 16:01:02 2015 Thomas Decamp
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_pustr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
