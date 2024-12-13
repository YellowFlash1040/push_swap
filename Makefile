CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE := make -s

SRC := $(filter-out main.c, $(wildcard *.c))
OBJ := $(SRC:.c=.o)
LIBFT_DIR := ./libft
LIBFT := libft.a

NAME := push_swap
LIB_PUSH_SWAP := $(NAME).a

all: $(NAME)

$(NAME): $(OBJ)
#	@mv $(LIBFT) $(LIB_PUSH_SWAP)
	@ar -src $(LIB_PUSH_SWAP) $(OBJ)
	@$(CC) -g main.c $(LIB_PUSH_SWAP) -o $(NAME)

# $(LIBFT):
# 	@cd $(LIBFT_DIR); $(MAKE); $(MAKE) bonus; cp $(LIBFT) ../$(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	@rm -f $(OBJ) $(LIB_PUSH_SWAP)
#	@$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re