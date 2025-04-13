# === Colors ===
RED     	= \033[0;31m
GREEN   	= \033[0;32m
YELLOW  	= \033[0;33m
BLUE    	= \033[0;34m
MAGENTA 	= \033[0;35m
CYAN    	= \033[0;36m
RESET   	= \033[0m
BOLD		= \033[1m
UNDERLINE 	= \033[4;32m
GREEN_BG 	= \033[42m

NAME = so_long

# Paths
LIB_DIR = libs
LIBFT_DIR = $(LIB_DIR)/libft
MINILIBX_DIR = $(LIB_DIR)/minilibx-linux
SRC_DIR = src
OBJ_DIR = obj
HEADERS_DIR = include

# Links
MINILIBX_URL = https://cdn.intra.42.fr/document/document/31497/minilibx-linux.tgz

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(HEADERS_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# Linker/Loader ld
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Sources
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/hooks.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/player_utils.c \
		$(SRC_DIR)/program_utils.c \
		$(SRC_DIR)/map_utils.c \
		$(SRC_DIR)/parsing.c

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ??? fare un comando che faccia anche:
# sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

# Commands (da includere minilibx)
all: $(NAME)
	@echo "$(GREEN)---- Building of $(NAME) ----$(RESET)";

# to do includere minilibx
$(NAME):  $(MINILIBX) $(OBJS) $(LIBFT)
	@echo "$(CYAN)---- Linking target $@ ---- $(RESET)using $^"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(LIBFT):
	@echo "$(RED)---- Libft not found ----$(RESET)"

$(MINILIBX): | $(MINILIBX_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	@$(MAKE) -C $(MINILIBX_DIR) --quiet

$(MINILIBX_DIR):
	@echo "$(YELLOW)---- minilibx-linux directory not found, downloading and extracting$(RESET)"
	@curl -L $(MINILIBX_URL) | tar xz -C $(LIB_DIR)
	@echo "---- removing minilibx-linux.tgz"
	@rm -f $(LIB_DIR)/minilibx-linux.tgz

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(MAGENTA)---- Create folder $@ $(RESET)"
	mkdir -p $(OBJ_DIR)

# Remove only temporary files
clean:
	@echo "$(RED)---- Removing .o files in $(NAME)----$(RESET)"
	@rm -rf $(OBJ_DIR) 
	@echo "---- cleaning minilibx ----"
	@$(MAKE) clean -C $(MINILIBX_DIR)

# Remove temporary files and executables
fclean: clean 
	@echo "$(RED)---- Removing executable $(NAME) ----$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)---- cleaning minilibx ----$(RESET)"
	@$(MAKE) clean -C $(MINILIBX_DIR)

re: fclean all 
 
.PHONY: all clean fclean re
