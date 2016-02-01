/*
** main.c for Minitalk in /PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 09:51:53 2016 Antoine Baché
** Last update Sat Jan 30 22:00:31 2016 Antoine Baché
*/

#include "client.h"

int	client(char *pid, char *msg)
{
  if (check_pid(pid) || send_msg(pid, msg))
    return (1);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (*env == NULL || ac != 3 || client(av[1], av[2]))
    {
      write(2, "Usage: ./client pid msg\n", 24);
#ifdef	DEBUG
      write(1, "Client Status: KO\n", 18);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(1, "Client Status: OK\n", 18);
#endif
  return (0);
}
