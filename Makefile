# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 16:32:39 by naotegui          #+#    #+#              #
#    Updated: 2024/06/04 16:43:42 by naotegui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
MLX			=	-lXext -lX11 -lm -lbsd 

#Nombre ejecutable
NAME		=	so_long

#Ficheros
SRC_FILES	= main \
			  checking_things \
            close_game \
            floodfill \
            game_bugs \
            take_map \
            image_desing \
            playing_map \
            put_image
	

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT		=	libft_gnl
MINILIBX	= 	minilibx-linux
FT_PRINTF	=	ft_printf

#Librerias 
LIBS		= $(MINILIBX)/libmlx.a $(MLX) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a

#Directorios
SRC_DIR = src/
OBJ_DIR = obj/

# Colores
GREEN       = \033[0;32m]
YELLOW      = \033[1;33m]
RED         = \033[0;31m]
NC          = \033[0m]


# REGLAS # 
all: minilibx libft  $(NAME)

#Compilar 
$(NAME):$(OBJ)
		@$(CC) $(OBJ) $(LIBS) -o $(NAME)
		@echo "$(GREEN)so_long HAS BEEN COMPILED!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled!$(NC)"
	
#compilar librerias individuales
libft:
	@echo "$(YELLOW)COMPILING LIBFT...$(NC)"
	@$(MAKE) -C ./$(LIBFT)
	@$(MAKE) -C ./$(FT_PRINTF)
	@echo "$(GREEN)LIBFT & PRINTF HAS BEEN COMPILED$(NC)"

minilibx:
	@echo "$(YELLOW)COMPILING MINILIBX...$(NC)"
	@$(MAKE) -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX HAS BEEN COMPILED$(NC)"
	
# Eliminar tmp mlx
fclean_mlx:
	@make fclean -C ./$(MINILIBX)
	@echo "$(RED)MINILIBX FULL CLEANED!$(NC)"


# Eliminar tmp libft
fclean_libft:
	@make fclean -C ./$(LIBFT)
	@echo "$(RED)LIBFT FULL CLEANED!$(NC)"

fclean_printf:
	@make fclean -C ./$(FT_PRINTF)
	@echo "$(RED)PRINTF FULL CLEANED!$(NC)"

# Eliminar temporales
clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)OBJS AND DIRECTORY CLEANED!$(NC)"


# Eliminar temporales y ejecutable fclean_mlx
fclean: clean  fclean_libft fclean_printf
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"

re: fclean all

.PHONY: all clean fclean re
