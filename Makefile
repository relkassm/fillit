NAME = fillit
SRC  = src/main.c
SRC += src/backtracking.c src/check.c src/free.c src/get_tetris_cord_index.c src/count_tetris_input.c
FLAG =  -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	make -C libft/
	gcc  -o $(NAME) $(FLAG) $(SRC) libft/libft.a 

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all 
