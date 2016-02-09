/*
** send_pid.c for Minitalk in /PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Feb  7 15:31:08 2016 Antoine Baché
** Last update Tue Feb  9 11:38:16 2016 Antoine Baché
*/

#include "client.h"

void		send_pid(unsigned int pid, unsigned int c_pid)
{
  int		i;
  unsigned int	mask;

  mask = 1;
  i = -1;
  while (++i != 32)
    {
      ((c_pid & mask) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2));
      c_pid >>= 1;
      usleep(1000);
    }
}
