/*
** response.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 31 01:11:02 2016 Antoine Baché
** Last update Sun Feb  7 13:58:11 2016 Antoine Baché
*/

#include "server.h"

void		display_char(char value)
{
  static int   	loop = 7;
  static char	msg = 0;

  if (loop == -1)
    {
      write(1, &msg, 1);
      loop = 7;
      msg = 0;
    }
  if (value == 1)
    msg |= (1 << (value * loop));
  --loop;
}

void	sig_1(UNUSED int signum, siginfo_t *sig, UNUSED void *data)
{
  display_char(1);
  kill(sig->si_pid, SIGUSR1);
}

void	sig_2(UNUSED int signum, siginfo_t *sig, UNUSED void *data)
{
  display_char(0);
  kill(sig->si_pid, SIGUSR1);
}
