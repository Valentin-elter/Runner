##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	= 	my_putchar.c			\
		my_putstr.c			\
		fill_game.c			\
		fill_supp.c			\
		score.c				\
		move.c				\
		reset.c				\
		display.c			\
		fill_all.c			\
		collision.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
	$(NAME)
