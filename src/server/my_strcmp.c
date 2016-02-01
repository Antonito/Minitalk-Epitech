/*
** my_strcmp.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 31 01:21:01 2016 Antoine Baché
** Last update Sun Jan 31 01:21:48 2016 Antoine Baché
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && *str != '\0' && (str++) && (++i));
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;
  int	t;

  i = 0;
  j = 0;
  t = my_strlen(s1);
  if (t < my_strlen(s2))
    t = my_strlen(s2);
  while (i < t + 1 && !j)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return (j);
}
