/*
** protocols.c for Minitalk in /PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:41:38 2016 Antoine Baché
** Last update Sun Feb  7 16:44:26 2016 Antoine Baché
*/

#include "client.h"

void	sig_hand(UNUSED int sig)
{
  return ;
}

void	start_protocol(unsigned int pid, t_msg *start)
{
  ((start->bits.eight) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.seven) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.six) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.five) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.four) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.three) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.two) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
  ((start->bits.one) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  usleep(10000);
}

int		send_msg(char *pid_char, char *msg)
{
  int		pid;
  unsigned int	i;
  t_msg		start;

  pid = my_getnbr(pid_char);
  i = -1;
  if (msg == NULL || write(1, "\n", 1) < 0)
    return (1);
  send_pid(pid, getpid());
  signal(SIGUSR1, sig_hand);
  while (msg[++i] != '\0')
    {
      start.message = msg[i];
      start_protocol(pid, &start);
    }
  start.message = 0;
  start_protocol(pid, &start);
  usleep(100000);
  return (0);
}
