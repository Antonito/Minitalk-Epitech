/*
** common.h for Minitalk in /PSU_2015_minitalk/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:13:30 2016 Antoine Baché
** Last update Mon Feb  1 09:02:49 2016 Antoine Baché
*/

#ifndef COMMON_H_
# define COMMON_H_
# define UNUSED __attribute__((unused))
# define _POSIX_SOURCE
# define _BSD_SOURCE
# define _DEFAULT_SOURCE

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# ifdef	DEBUG
#  include <stdio.h>
# endif /* DEBUG */

#endif /* !COMMON_H_ */
