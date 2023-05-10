CC = gcc
FLAGS = -Wall -Wextra -Werror -O2 -g
RM = rm -rf

SRC = main.c				\
	  put_pixel.c			\
	  map_load.c			\
	  parse_colors.c		\
	  parse_textures.c		\
	  parse_map.c			\
	  mlx_events.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = cub3D

INCLUDES = -Iincludes/
LIB = libft/libft.a mlx_mac/libmlx.a

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

all: ${NAME}

${LIB}:
	cd mlx_mac/ && make
	cd libft/ && make

$(NAME): ${LIB} $(OBJ)
	$(CC) ${FLAGS} $(OBJ) -L./libft -L./mlx_mac -lmlx -lm -lft -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	cd libft/ && make clean
	cd mlx_mac/ && make clean
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME}
	${RM} ${LIB}

.PHONY: all re clean fclean
