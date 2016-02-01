/*
** my_getnbr.c for Minitalk in //PSU_2015_minitalk/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 30 20:13:17 2016 Antoine Baché
** Last update Sat Jan 30 20:15:22 2016 Antoine Baché
*/

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  long	r;

  i = 0;
  s = 1;
  r = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	s = -s;
      ++i;
    }
  str += i;
  i = 0;
  while (str[i] > '/' && str[i] < ':')
    {
      r *= 10;
      r = r + str[i] - '0';
      ++i;
    }
  return (r > 2147483647 || r < -2147483648 ? 0 : s * r);
}
