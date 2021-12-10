NAME = so_long
BONUS = checker

SRCS =  $(shell find src -type f -name "*.c")
BONUS_SRCS =  

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

INCLUDES = -I ./inc 

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LINK_LIBFT = -L./libft -lft

all : libft $(NAME)

libft:
	@$(MAKE) all -sC ./libft

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit $(LINK_LIBFT) -o $(NAME)

# bonus: $(BONUS_OBJS)
# 	@$(CC) $(INCLUDES) $(BONUS_OBJS) $(LINK_LIBFT) -o $(BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx $(INCLUDES) $< -c -o $@

$(NAME): $(OBJS)
	gcc -Wall -Werror -Wextra ${OBJS} ${LINK_LIBFT} -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lz -lm -o ${NAME}

clean :
	@rm -rf $(wildcard ./*.o)
	@rm -rf $(wildcard ./*/*.o)
	@rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	@$(MAKE) fclean -sC ./libft
	@$(MAKE) clean -sC ./minilibx
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re : fclean all

.PHONY: all libft clean fclean re