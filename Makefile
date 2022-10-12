NAME = so_long

SRC	= main.c \
	map_check.c \
	window.c \

DIR 		= ${addprefix srcs/,${SRC}}

HEAD		= -I ft -I include -I mlx

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror -g

OBJS 		= ${DIR:.c=.o}

LD_FLAG		= -L ft -L mlx

MLX_FLAG	= -lm -lmlx -lXext -lX11 -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft
	make -C mlx
	$(CC) $(CFLAGS) $(LD_FLAG) $(OBJS) -o $(NAME) $(MLX_FLAG)

.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean:
	make clean -C ft
	make clean -C mlx
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C ft 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re