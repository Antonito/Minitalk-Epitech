##
## Makefile for Minitalk in /PSU_2015_minitalk
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Jan 29 09:43:20 2016 Antoine Baché
## Last update Thu Feb 18 16:24:42 2016 Antoine Baché
##

DEBUG=			no

SRC_PREFIX=		src/client/

SRC_FILES=		main.c		\
			check_pid.c	\
			protocols.c	\
			send_pid.c	\
			my_getnbr.c

SRC_SERVER_PREFIX=	src/server/

SRC_SERVER_FILES=	main.c		\
			response.c	\
			my_strcmp.c	\
			my_bzero.c	\
			get_c_pid.c	\
			my_put_nbr.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_SERVER=		$(addprefix $(SRC_SERVER_PREFIX),$(SRC_SERVER_FILES))

NAME=			client/client

NAME_SERVER=		server/server

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

OBJ_SERVER=		$(SRC_SERVER:.c=.o)

$(NAME_SERVER):	$(NAME) $(OBJ_SERVER)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled server"
	@$(CC) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME):	$(OBJ)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled client"
	@$(CC) $(OBJ) -o $(NAME)

%.o:%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME) $(NAME_SERVER)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_SERVER)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting" $(NAME) "..."
	@$(RM) $(NAME)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting" $(NAME_SERVER) "..."
	@$(RM) $(NAME_SERVER)

re:	fclean all

.PHONY:	all clean fclean re
