.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

#****************************************************************************#
#									TESTS 									 #
#****************************************************************************#

NAME = fractol

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./includes/libft/
MLX_PATH = ./includes/mlx/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC_LIB = $(addprefix -I, $(INC_PATH))
INC_MLX = $(addprefix -I, $(INC_PATH))

SRC_NAME =	burning_ship.c			\
			celtic_mandelbar.c		\
			change_fractol.c		\
			draw.c					\
			julia.c					\
			key_event.c				\
			list.c					\
			main.c					\
			mandelbar.c				\
			mandelbrot.c			\
			mouse_event.c			\
			window.c				\
			
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft -L $(MLX_PATH) -l mlx -framework OpenGL -framework AppKit
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(INC) -o $@ -c $<

#****************************************************************************#
#									OTHER			 						 #
#****************************************************************************#

lib_refresh:
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)

norm:
	@echo "$(YELLOW)"
	@norminette -R CheckForbiddenSourceHeader

clean:
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)

re: fclean all
