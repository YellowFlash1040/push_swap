# Compiler and Flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Files
FILES   := args_parser.c main.c phase1.c phase2_part1.c phase2_part2.c \
           print.c push_swap.c sort.c stack_advanced.c stack_basic.c

# Sources and Objects
SRCS    := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS    := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Output File
NAME    := push_swap

# Colors for Output
GREEN   := \033[0;32m
RESET   := \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)Compiled $(NAME) successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Removed object files."

# Clean up All Generated Files
fclean: clean
	@rm -f $(NAME)
	@echo "Removed $(NAME)."

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
