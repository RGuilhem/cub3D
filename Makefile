CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf

SRC = main.c			\
	  error_put.c

SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = cub3D

INCLUDES = -Iinclude/
LIB = libft.a

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

all: ${NAME}

${LIB}:
	cd libft/ && make && cp -v libft.a ../

$(NAME): ${LIB} $(OBJ)
	$(CC) ${FLAGS} $(OBJ) $(INCLUDES) -L. -lft -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	cd libft/ && make clean
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME}
	${RM} ${LIB}

.PHONY: all re clean fclean
