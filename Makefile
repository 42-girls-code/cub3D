# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 09:15:03 by ingrid            #+#    #+#              #
#    Updated: 2026/05/13 12:39:32 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
LIBFT_DIR = lib/libft
MINILIBX_DIR = lib/minilibx
LIBFT_INC = $(LIBFT_DIR)/inc
MINILIBX_INC = $(MINILIBX_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lX11 -lm -lz

INCLUDES = -I$(INC_DIR) -I$(LIBFT_INC) -I$(MINILIBX_INC)

# Library
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Colors
RESET = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m

# Files
SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/utils/utils.c \
		$(SRC_DIR)/utils/map_utils.c \
		$(SRC_DIR)/parser/parse_color.c \
		$(SRC_DIR)/parser/parse_texture.c \
		$(SRC_DIR)/parser/parse_map.c \
		$(SRC_DIR)/parser/valid_map.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		@echo "$(YELLOW)[Cub3D]$(RESET) Linking objects..."
		@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
		@echo "$(GREEN)[OK]$(RESET) $(NAME) compiled successfully."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/cub3d.h
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
		@echo "$(YELLOW)[LIB]$(RESET) Building libft..."
		@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@echo "$(RED)[FCLEAN]$(RESET) '$(NAME)' removed."

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_DIR) --silent
		@echo "$(RED)[FCLEAN]$(RESET) '$(NAME)' removed."

re: fclean all

PHONY: all clean fclean re
