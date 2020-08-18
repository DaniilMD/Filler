NAME = openelop.filler

SRC = main.c get_map_and_token.c work_with_walls.c \
	get_started.c work_with_mass.c main_algs.c graphics.c \
	play_filler.c extra_graphics.c event_work.c make_title.c \

OBJ = $(SRC:.c=.o)

HEADER = filler.h

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L ./mlx/ -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(SRC) -o $(NAME) -L libft -lft $(MLX_FLAGS)

%.o:%.c $(HEADER)
	@gcc $(FLAGS) -I . -c $< -o $@

clean:
	@/bin/rm -f *~
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
