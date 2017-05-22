NAME = fractol
MINILIB_X = libraries/minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

SRC =	\
		srcs/main.c \
		srcs/frac_files/mandelbrot.c \
		srcs/frac_files/julia.c \
		srcs/frac_files/burning_ship.c \
		srcs/input_files/initialize_var.c \
		srcs/input_files/hooks.c \
		srcs/input_files/init_colors.c \

FRAC_OBJ = 	\
		mandelbrot.o \
		julia.o \
		burning_ship.o

INPUT_OBJ =	\
		main.o \
		mouse_and_keypress.o \
		hooks.o \
		init_colors.o \
		initialize_var.o

OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) includes/fractal.h
	make -C libraries/libft/
	gcc $(FLAGS) -I libraries//libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libraries/libft/ -lft $(MINILIB_X) -framework OpenGL -framework AppKit

clean:
	make -C libraries/libft/ clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(FRAC_OBJ)
	/bin/rm -f $(INPUT_OBJ)

fclean: clean
	make -C libraries/libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean