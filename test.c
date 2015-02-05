/*
** test.c for test.c in /home/brunne_s/rendu/SysUnix/PSU_2014_malloc
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Tue Feb  3 15:37:05 2015 Steeven Brunner
** Last update Tue Feb  3 15:38:29 2015 Steeven Brunner
*/

#include <stdio.h>

int	main()
{
  int	x;
  char	*str = "Toto";

  printf("Adress of main = %p\nAdress of x = %p\nAdress of str = %p\n", &main, &x, &str);
}
