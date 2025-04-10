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
CFLAGS = -Wall -Werror -Wextra -I$(HEADERS_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# Linker/Loader ld
# Serve anche -Imlx ?
LDFLAGS = $(LIBFT_FLAGS) $(MINILIBX_FLAGS)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

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
	@echo "---- Building executable $(NAME)"

# to do includere minilibx
$(NAME):  $(MINILIBX) $(OBJS) $(LIBFT)
	@echo "---- Linking target $@ ---- using $^ ----"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(LIBFT):
	@echo "---- Compiling libft"

$(MINILIBX): | $(MINILIBX_DIR)
	@echo "---- Compiling minilibx-linux"
	@$(MAKE) -C $(MINILIBX_DIR) --quiet

$(MINILIBX_DIR):
	@echo "---- minilibx-linux directory not found, downloading and extracting"
	@curl -L $(MINILIBX_URL) | tar xz -C $(LIB_DIR)
	@echo "---- removing minilibx-linux.tgz"
	@rm -f $(LIB_DIR)/minilibx-linux.tgz

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "---- Compiling $< ----> $@ ----"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "---- Create folder $@"
	mkdir -p $(OBJ_DIR)

# Remove only temporary files
clean:
	@echo "---- Removing $(OBJS)" 
	@rm -rf $(OBJ_DIR) 
	@echo "---- cleaning minilibx"
	@$(MAKE) clean -C $(MINILIBX_DIR)

# Remove temporary files and executables
fclean: clean 
	@echo "---- Removing executable $(NAME)" 
	@rm -f $(NAME)
	@echo "---- cleaning minilibx"
	@$(MAKE) clean -C $(MINILIBX_DIR) 

re: fclean all 
 
.PHONY: all clean fclean re
