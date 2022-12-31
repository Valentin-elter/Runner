##
## EPITECH PROJECT, 2019
## delivery
## File description:
## Makefile
##

NAME	=	my_runner

all:
	make -C lib/my/
	gcc -o $(NAME) main.c -l csfml-audio -l csfml-window -l csfml-system -l csfml-graphics -L ./lib/my -lmy

clean:
	make -C lib/my clean

fclean:
	make -C lib/my fclean

re:
	make -C lib/my re
	gcc -o $(NAME) main.c -L ./lib/my -lmy

debug:
	gcc -o $(NAME) -g -Wall -Wextra main.c -L ./lib -lmy
