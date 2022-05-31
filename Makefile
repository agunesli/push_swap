SRC_F = parsing.c utils.c utils_lst.c get_start.c\
 	ft_split.c ft_atoi.c ft_substr.c ft_strdup.c

SRC_M = pushswap.c

SRC_B = 

SRC_H	= pushswap.h

OBJ_M	= $(SRC_M:%.c=%.o)

OBJ_B	= $(SRC_B:%.c=%.o)

OBJ_F	= $(SRC_F:%.c=%.o)

NAME_M	=	push_swap
NAME_B	=	checker
CC		=	gcc
#FLAGS	=	-g3 -Wall -Wextra -Werror -fsanitize=address
FLAGS	=	-g3 -Wall -Wextra -Werror
RM		=	rm -rf

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME_M): $(OBJ_M) $(OBJ_F) $(SRC_H)
		$(CC) $(OBJ_M) $(OBJ_F) -o $(NAME_M)

all:	$(NAME_M)

$(NAME_B):	$(OBJ_B) $(OBJ_F) $(OBJ_H)
		$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME_B)

bonus:	$(NAME_B)

clean:
		$(RM) $(OBJ_M) $(OBJ_F) $(OBJ_B)

fclean:	clean
		$(RM) $(NAME_M) $(NAME_B)

re:		fclean all 

.PHONY:		all clean fclean bonus re
