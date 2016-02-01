/*
** my_put_nbr.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:23:24 2016 Antoine Baché
** Last update Fri Jan 29 10:27:56 2016 Antoine Baché
*/

#include "server.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  write(1, "-2147483648", 11);
	  return (11);
	}
      my_putchar('-');
      i++;
      nb = -nb;
    }
  if (nb >= 10)
    i += my_put_nbr_unsigned(nb / 10);
  my_putchar(nb % 10 + 48);
  return (i);
}

int	my_put_nbr_unsigned(unsigned int nb)
{
  int	i;

  i = 1;
  if (nb >= 10)
    i += my_put_nbr_unsigned(nb / 10);
  my_putchar(nb % 10 + 48);
  return (i);
}
