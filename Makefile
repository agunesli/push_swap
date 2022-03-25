SRC_F	= ft_atoi.c test.c

#SRC_M = push_swap.c

SRC_H	= push_swap.h

#OBJ_M	= $(SRC_M:%.c=%.o)

OBJ_F	= $(SRC_F:%.c=%.o)

NAME	=	push_swap
CC		=	gcc
#FLAGS	=	-g3 -Wall -Wextra -Werror -fsanitize=address
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME):$(OBJ_F) $(SRC_H)
		$(CC) $(OBJ_M) $(OBJ_F) -o $(NAME)

all:	$(NAME)

bonus:	$(OBJ_F) $(OBJ_B)
		$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME)

clean:
		$(RM) $(OBJ_M) $(OBJ_F) $(OBJ_B)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean bonus re
