/*
** client.h for Minitalk in /PSU_2015_minitalk/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:01:08 2016 Antoine Baché
** Last update Sun Feb  7 15:34:35 2016 Antoine Baché
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "common.h"

typedef	struct	s_bitfield
{
  unsigned int 	one : 1;
  unsigned int 	two: 1;
  unsigned int 	three: 1;
  unsigned int 	four: 1;
  unsigned int 	five: 1;
  unsigned int 	six: 1;
  unsigned int 	seven: 1;
  unsigned int 	eight: 1;
}		t_bitfield;

typedef union	u_msg
{
  t_bitfield	bits;
  char		message;
}		t_msg;

void	send_pid(unsigned int, unsigned int);
void	ping_pong(void);
int	check_pid(char *);
int	send_msg(char *, char *);
void	start_protocol(unsigned int, t_msg *);
int	my_getnbr(char *);

#endif /* !CLIENT_H_ */
