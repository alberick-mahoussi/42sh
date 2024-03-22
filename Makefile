##
## EPITECH PROJECT, 2022
## mnsh2
## File description:
## Makefile
##

SRC	=	$(shell find ./src -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all :	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean :clean
	rm -f $(NAME)

re :	fclean all
