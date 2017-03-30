NAME = fractol
MINILIB_X = minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

SRC =	\
		main.c \
		hooks.c \
		initialize_var.c \
		mandelbrot.c \
		keys_and_colors.c \
		julia.c \
		mouse_and_keypress.c


OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) fractol.h
	make -C libft/
	gcc $(FLAGS) -I /libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft $(MINILIB_X) -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all