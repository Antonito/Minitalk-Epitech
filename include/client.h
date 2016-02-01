/*
** client.h for Minitalk in /PSU_2015_minitalk/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:01:08 2016 Antoine Baché
** Last update Sun Jan 31 01:06:38 2016 Antoine Baché
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "common.h"

void	ping_pong(void);
int	check_pid(char *);
int	send_msg(char *, char *);
void	start_protocol(int, t_msg *);
int	my_getnbr(char *);

#endif /* !CLIENT_H_ */
