SRCS_CLIENT = minitalk_utils.c \
	client.c
SRCS_SERVER = minitalk_utils.c \
	server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(OBJS_SERVER)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(OBJS_SERVER) -o $(NAME_SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
