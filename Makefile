NAME = so_long

SRC	= main.c \
	chained.c \
	map_check_1.c \
	map_check_2.c \
	map_check_3.c \
	map_check_4.c \
	game_1.c \
	game_2.c \
	events.C \

DIR 		= ${addprefix srcs/,${SRC}}

HEAD		= -I ft -I include -I mlx -I gnl

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror -g

OBJS 		= ${DIR:.c=.o}

LD_FLAG		= -L ft -L mlx -L gnl

MLX_FLAG	= -lm -lmlx -lXext -lX11 -lft -lgnl

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft
	make -C mlx
	make -C gnl
	$(CC) $(CFLAGS) $(LD_FLAG) $(OBJS) -g -o $(NAME) $(MLX_FLAG)

.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean:
	make clean -C ft
	make clean -C mlx
	make clean -C gnl
	rm -f $(OBJS)

fclean: clean
	make fclean -C ft
	make fclean -C gnl
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re