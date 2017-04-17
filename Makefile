NAME = fractal
MINILIB_X = minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

SRC =	\
		main.c \
		frac_files/mandelbrot.c \
		frac_files/julia.c \
		frac_files/burning_ship.c \
		input_files/initialize_var.c \
		input_files/hooks.c \
		input_files/init_colors.c \

FRAC_OBJ = 	\
		mandelbrot.o \
		julia.o \
		burning_ship.o

INPUT_OBJ =	\
		mouse_and_keypress.o \
		hooks.o \
		keys_and_colors.o \
		initialize_var.o


OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) includes/fractol.h
	make -C libft/
	gcc $(FLAGS) -I /libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft $(MINILIB_X) -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(FRAC_OBJ)
	/bin/rm -f $(INPUT_OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean