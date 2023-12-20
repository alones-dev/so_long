# Base
NAME		=	so_long
CC			=	cc
FLAGS		=	-g3 -Wall -Wextra -Werror

# Base compiled files
INC_FOLDER	=	inc/
SRC_FOLDER	=	srcs/
SRC_FILES	=	main.c map.c check_map.c flood_map.c utils.c draw.c move.c
OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

# Printf part
PRINTF_PATH =	ft_printf/
PRINTF_LIB	=	$(PRINTF_PATH)libftprintf.a

# Printf part
GNL_PATH =	get_next_line/
GNL_LIB	=	$(GNL_PATH)get_next_line.a

# Libft part
LIBFT_PATH	=	libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a

# MiniLibX includes
MLX_PATH	=	mlx/
MLX_INCLUDE =	-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Colors
DEFAULT		=	\033[0;39m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

# Compile part
%.o: %.c
	@echo "$(YELLOW)- Compiling $<$(DEFAULT)"
	@$(CC) $(FLAGS) -I$(INC_FOLDER) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(GNL_PATH) -I/usr/include -I$(MLX_PATH) -c $< -o $@

$(NAME): 	$(OBJS)
	@make -C $(LIBFT_PATH) --no-print-directory -s
	@make -C $(PRINTF_PATH) --no-print-directory -s
	@make -C $(GNL_PATH) --no-print-directory -s
	@make -C $(MLX_PATH) --no-print-directory -s
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX_INCLUDE) -o $(NAME)
	@echo "$(GREEN)♫ $(NAME) compiled successfully! ♫$(DEFAULT)"

# Mandatory rules
all:		$(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_PATH) --no-print-directory -s
	@make clean -C $(PRINTF_PATH) --no-print-directory -s
	@make clean -C $(GNL_PATH) --no-print-directory -s
	@make clean -C $(MLX_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) cleaned successfully! ♫$(DEFAULT)"

fclean:		clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) --no-print-directory -s
	@make fclean -C $(PRINTF_PATH) --no-print-directory -s
	@make fclean -C $(GNL_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) executable files cleaned! ♫$(DEFAULT)"

re:			fclean all
			@echo "$(GREEN)♫ $(NAME) recompiled successfully! ♫$(DEFAULT)"

.PHONY:		all clean fclean re norm