CC = gcc-11

CFLAGS= -Wall -Wextra -Werror

NAME=cub3D

NAME_B = cub3D_bonus

PARSING=utils.c parsing.c my_list.c check.c utils2.c check2.c my_free.c utils3.c

EXECUTION= first_gridlines.c raycast.c execution_utils.c draw.c player_move.c key.c\
	
BONUS = draw_minimap.c init.c main.c execution.c mouse.c weapon.c

SRCS =  ./maindatory/main.c ./maindatory/execution.c $(addprefix ./maindatory/parsing/, $(PARSING)) $(addprefix ./maindatory/execution/, $(EXECUTION))

SRCS_B = $(addprefix ./maindatory/parsing/, $(PARSING)) $(addprefix ./maindatory/execution/, $(EXECUTION)) $(addprefix ./bonus/, $(BONUS))

OBJECTS = $(SRCS:.c=.o)

OBJECTS_B = $(SRCS_B:.c=.o)

all : $(NAME)

bonus : $(NAME_B)

libft/libft.a : $(IMP)
	@make -C libft

$(NAME)	: libft/libft.a $(OBJECTS) 
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L libft -lft -L libft/ft_printf -lftprintf -lmlx -lm -lX11 -lXext
	@echo "\033[0;31m CUB3D is compiling ...\033[0m"

$(NAME_B)	: libft/libft.a $(OBJECTS_B) 
	@$(CC) $(CFLAGS) $(OBJECTS_B) -o $(NAME_B) -L libft -lft -L libft/ft_printf -lftprintf -lmlx -lm -lX11 -lXext
	@echo "\033[0;31m CUB3D_BONUS is compiling ...\033[0m"

clean : 
	@rm -rf $(OBJECTS) $(OBJECTS_B)
	@make clean -C libft

fclean : clean
	@rm -rf $(NAME) $(NAME_B)
	@make fclean -C libft
	@echo "\033[0;32m all clean \033[0m"

re : fclean all

phony : all clean fclean re libft

.SILENT : $(OBJECTS) $(OBJECTS_B)
