/*
** common.h for Minitalk in /PSU_2015_minitalk/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:13:30 2016 Antoine Baché
** Last update Sat Jan 30 21:11:45 2016 Antoine Baché
*/

#ifndef COMMON_H_
# define COMMON_H_
# define UNUSED __attribute__((unused))
# define _POSIX_SOURCE
# define _BSD_SOURCE
# define _DEFAULT_SOURCE

# include <sys/types.h>
# include <signal.h>
# ifdef	DEBUG
#  include <stdio.h>
# endif /* DEBUG */
# include <unistd.h>

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

#endif /* !COMMON_H_ */
