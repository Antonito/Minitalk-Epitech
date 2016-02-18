/*
** protocols.c for Minitalk in /PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:41:38 2016 Antoine Baché
** Last update Thu Feb 18 23:42:28 2016 Antoine Baché
*/

#include "client.h"

void	sig_hand(UNUSED int sig)
{
  return ;
}

void	start_protocol(unsigned int pid, char msg)
{
  int		i;
  unsigned char	mask;

  mask = 128;
  i = -1;
  while (++i != 8)
    {
      ((msg & mask) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
      mask >>= 1;
      usleep(10000);
    }
}

int    	send_msg(char *pid_char, char *msg)
{
  int	pid;
  int	i;

  if ((pid = my_getnbr(pid_char)) <= 0)
    return (1);
  i = -1;
  if (msg == NULL)
    return (1);
  send_pid(pid, getpid());
  if (signal(SIGUSR1, sig_hand) == SIG_ERR)
    return (2);
  while (msg[++i] != '\0')
    {
      start_protocol(pid, msg[i]);
    }
  start_protocol(pid, 0);
  usleep(350000);
  return (0);
}
