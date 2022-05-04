NAME = so_long
BONUS = checker

SRCS =  $(shell find src -type f -name "*.c")
BONUS_SRCS =  

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

INCLUDES = -I ./inc 

CC = gcc
# CFLAGS = -Wall -Werror -Wextra

LINK_LIBFT = -L./libft -lft

all : libft $(NAME)

libft:
	@$(MAKE) all -sC ./libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LINK_LIBFT) -o $(NAME)
# -framework OpenGL -framework AppKit
bonus: $(BONUS_OBJS)
	@$(CC) $(INCLUDES) $(BONUS_OBJS) $(LINK_LIBFT) -o $(BONUS)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	@rm -rf $(wildcard ./*.o)
	@rm -rf $(wildcard ./*/*.o)
	@rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	@$(MAKE) fclean -sC ./libft
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re : fclean all

.PHONY: all libft clean fclean re