/*
** my_bzero.c for Minitalk in /PSU_2015_minitalk/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 31 02:24:11 2016 Antoine Baché
** Last update Sun Jan 31 02:24:32 2016 Antoine Baché
*/

void		my_bzero(void *content, int size)
{
  unsigned char	*addr;

  addr = content;
  while (size--)
    addr[size] = 0;
}
