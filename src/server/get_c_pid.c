/*
** get_c_pid.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Feb  7 15:15:28 2016 Antoine Baché
** Last update Thu Feb 18 23:30:47 2016 Antoine Baché
*/

#include "server.h"

void	capture_pid(char value)
{
  static int	loop = 0;

  if (loop == 32)
    loop = 0;
  if (value == 1)
    g_infos.pid |= (1 << loop);
  ++g_infos.id;
  ++loop;
}

void	pid1(UNUSED int sig)
{
  capture_pid(1);
}

void	pid2(UNUSED int sig)
{
  capture_pid(0);
}

int	get_c_pid(void)
{
  if (signal(SIGUSR1, &pid1) == SIG_ERR ||
      signal(SIGUSR2, &pid2) == SIG_ERR)
    return (1);
  while (g_infos.id != 32)
    {
      sleep(1);
    }
  return (0);
}
