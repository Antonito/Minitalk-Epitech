/*
** protocols.c for Minitalk in /PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:41:38 2016 Antoine Baché
** Last update Mon Feb  1 09:00:28 2016 Antoine Baché
*/

#include "client.h"

void	sig_hand(UNUSED int sig)
{
  usleep(0);
}

void	start_protocol(int pid, t_msg *start)
{
  ((start->bits.eight) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.seven) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.six) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.five) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.four) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.three) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.two) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
  ((start->bits.one) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
  pause();
}

int	send_msg(char *pid_char, char *msg)
{
  int	pid;
  int	i;
  t_msg	start;

  pid = my_getnbr(pid_char);
  i = -1;
  if (msg == NULL || write(1, "\n", 1) < 0)
    return (1);
  signal(SIGUSR1, sig_hand);
  while (msg[++i] != '\0')
    {
      start.message = msg[i];
      start_protocol(pid, &start);
    }
  start.message = 0;
  start_protocol(pid, &start);
  return (0);
}
