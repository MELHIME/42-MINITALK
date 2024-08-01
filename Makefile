SRCS=client.c client_bonus.c server.c server_bonus.c minitalk_utils.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror
LIBFT_AR=./libft/libft.a

all : $(LIBFT_AR) client server 


bonus : $(LIBFT_AR) client_bonus server_bonus

client: client.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

client_bonus : client_bonus.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

server: server.o minitalk_utils.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

server_bonus: server_bonus.o minitalk_utils.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

$(LIBFT_AR):
	@make -C ./libft

clean:
	@make -C ./libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re
                                                                                       