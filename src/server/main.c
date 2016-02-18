/*
** main.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:03:58 2016 Antoine Baché
** Last update Thu Feb 18 23:31:28 2016 Antoine Baché
*/

#include "server.h"

t_infos	g_infos;

void	set_infos(void)
{
  g_infos.id = 0;
  g_infos.pid = 0;
}

int	server(int args)
{
  if (args < 0)
    return (0);
  my_put_nbr((int)getpid());
  if (write(1, "\n", 1) < 0)
    return (1);
  set_infos();
  while (1)
    {
      if (g_infos.id == 0)
	{
	  if (get_c_pid())
	    return (1);
	  if (g_infos.pid != 0)
	    {
	      if (signal(SIGUSR1, &sig_1) == SIG_ERR ||
		  signal(SIGUSR2, &sig_2) == SIG_ERR)
		return (1);
	    }
	}
      if (usleep(100000) == 0)
	set_infos();
    }
  return (0);
}

int	check_args(int ac, char **av)
{
  if (ac > 1)
    {
      if (!my_strcmp("--help", av[1]))
	{
	  write(2, "Usage : ./server [--help / --infos]\n", 36);
	  return (-1);
	}
      else if (!my_strcmp("--infos", av[1]))
	return (1);
      else
	{
	  write(2, "Unrecognized option \"", 22);
	  write(2, av[1], my_strlen(av[1]));
	  write(2, "\"\nUsage : ./server [--help / --infos]\n", 38);
	  return (-1);
	}
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (*env == NULL || ac > 2 ||  server(check_args(ac, av)))
    {
#ifdef	DEBUG
      write(1, "Server Status: KO\n", 18);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(1, "Server Status: OK\n", 18);
#endif
  return (0);
}
