##
## Makefile for Minitalk in /PSU_2015_minitalk
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Jan 29 09:43:20 2016 Antoine Baché
## Last update Sun Jan 31 02:54:40 2016 Antoine Baché
##

DEBUG=			yes

SRC_PREFIX=		src/client/

SRC_FILES=		main.c		\
			check_pid.c	\
			protocols.c	\
			my_getnbr.c

SRC_SERVER_PREFIX=	src/server/

SRC_SERVER_FILES=	main.c		\
			response.c	\
			my_strcmp.c	\
			my_bzero.c	\
			my_put_nbr.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_SERVER=		$(addprefix $(SRC_SERVER_PREFIX),$(SRC_SERVER_FILES))

NAME=			client

NAME_SERVER=		server

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
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled server"
	@$(CC) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME):	$(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
	@tput sgr0
endif
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled client"
	@$(CC) $(OBJ) -o $(NAME)

%.o:	%.c
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME) $(NAME_SERVER)

clean:
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK"; tput sgr0
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_SERVER)

fclean:	clean
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)
	@$(RM) $(NAME_SERVER)

re:	fclean all

.PHONY:	all clean fclean re
