/*
** client.h for Minitalk in /PSU_2015_minitalk/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:01:08 2016 Antoine Baché
** Last update Thu Feb 18 23:41:00 2016 Antoine Baché
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "common.h"

void	send_pid(unsigned int, unsigned int);
void	ping_pong(void);
int	check_pid(char *);
int	send_msg(char *, char *);
void	start_protocol(unsigned int, char);
int	my_getnbr(char *);

#endif /* !CLIENT_H_ */
