
NAME = so_long

SRCS = main.c check_maps.c ft_itoa.c mlx_game.c utils.c move_game.c\
	./getnextline/get_next_line.c \
	./getnextline/get_next_line_utils.c \

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}
RM = rm -f

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Imlx -g -c $< -o ${<:.c=.o}

		
$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	
re: fclean all