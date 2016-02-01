/*
** check_pid.c for Minitalk in /PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:36:44 2016 Antoine Baché
** Last update Fri Jan 29 10:39:22 2016 Antoine Baché
*/

#include "client.h"

int	check_pid(char *pid)
{
  int	i;

  i = 0;
  while (pid[i])
    {
      if (pid[i] < '0' || pid[i] > '9')
	{
	  write(2, "Wrong PID\n", 10);
	  return (1);
	}
      ++i;
    }
  return (0);
}
