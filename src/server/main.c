/*
** main.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:03:58 2016 Antoine Baché
** Last update Sun Jan 31 15:43:41 2016 Antoine Baché
*/

#include "server.h"

void	prepare_sig(struct sigaction *sig1, struct sigaction *sig2)
{
  my_bzero(sig1, sizeof(struct sigaction));
  my_bzero(sig2, sizeof(struct sigaction));
  sig1->sa_flags = SA_SIGINFO | SA_RESTART;
  sig2->sa_flags = SA_SIGINFO | SA_RESTART;
  sig1->sa_handler = NULL;
  sig2->sa_handler = NULL;
  sig1->sa_sigaction = sig_1;
  sig2->sa_sigaction = sig_2;
}

int			server(int args)
{
  struct sigaction	sig1;
  struct sigaction	sig2;
  struct sigaction	old;

  if (args < 0)
    return (0);
  write(1, "Server PID: ", 12);
  my_put_nbr((int)getpid());
  if (write(1, "\n", 1) < 0)
    return (1);
  prepare_sig(&sig1, &sig2);
  my_bzero(&old, sizeof(struct sigaction));
  if (sigaction(SIGUSR1, &sig1, &old) < 0 ||
      sigaction(SIGUSR2, &sig2, &old) < 0)
    return (1);
  while (1)
    {
      pause();
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
