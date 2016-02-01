/*
** server.h for Minitalk in /PSU_2015_minitalk/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 29 10:12:32 2016 Antoine Baché
** Last update Mon Feb  1 09:02:08 2016 Antoine Baché
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "common.h"

void	my_bzero(void *, int);
int	my_strlen(char *);
int	my_strcmp(char *, char *);
void	display_char(char);
void	sig_1(int, siginfo_t *, void *);
void	sig_2(int, siginfo_t *, void *);
int	my_put_nbr(int);
int	my_put_nbr_unsigned(unsigned int);

#endif /* !SERVER_H_ */
