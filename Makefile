CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = main.c				\
	  put_pixel.c			\
	  map_load.c			\
	  parse_colors.c		\
	  parse_textures.c		\
	  parse_map.c			\
	  read_lines.c			\
	  draw_line.c			\
	  move_player.c			\
	  rotate_player.c		\
	  rotate_vec2f.c		\
	  setup_background.c	\
	  draw_rays.c			\
	  raycasting.c			\
	  cast_rays.c			\
	  dda.c					\
	  render_tex_line.c		\
	  minimap.c				\
	  handle_mice.c			\
	  free_utils.c			\
	  check_map.c			\
	  mlx_events.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = cub3D

INCLUDES = -Iincludes/
LIB = libft/libft.a mlx_mac/libmlx.dylib

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

all: ${NAME}

${LIB}:
	cd mlx_mac/ && make && cp libmlx.dylib ../
	cd libft/ && make

$(NAME): ${LIB} $(OBJ)
	$(CC) ${FLAGS} $(OBJ) -L./libft -L. -lmlx -lm -lft -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	cd libft/ && make clean
	cd mlx_mac/ && make clean
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME}
	${RM} ${LIB}
	$(RM) libmlx.dylib

.PHONY: all re clean fclean
