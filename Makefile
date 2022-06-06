SRC_F = parsing.c utils.c get_start.c \
	ft_split.c ft_atoi.c ft_substr.c ft_strdup.c

SRC_M = pushswap.c\
	algo_push_b.c algo_back_a.c algo_other.c algo_utils.c\
	push.c rotate.c swap.c

SRC_B = pushswap_bonus.c\
	push_bonus.c rotate_bonus.c swap_bonus.c \
	ft_strncmp.c get_next_line.c get_next_line_utils.c

SRC_H	= pushswap.h

SRC_HB	= pushswap_bonus.h

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

$(NAME_B):	$(OBJ_B) $(OBJ_F) $(OBJ_HB)
		$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME_B)

bonus:	$(NAME_B)

clean:
		$(RM) $(OBJ_M) $(OBJ_F) $(OBJ_B)

fclean:	clean
		$(RM) $(NAME_M) $(NAME_B)

re:		fclean all

.PHONY:		all clean fclean bonus re
