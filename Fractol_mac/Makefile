SRC = *.c

NAME = fractol

OBJ = *.o

CC = cc
#CFLAGS = -Wall -Werror -Wextra -I/usr/include -Imlx_linux -O3

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

%.o: %.c
#		$(CC) $(CFLAGS) -c $< -o $@
		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#$(NAME): $(OBJ)
#		$(CC) $(CFLAGS) -o $@ $(OBJ)




#bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all re fclean clean

