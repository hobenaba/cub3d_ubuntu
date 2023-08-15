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

all : libft $(NAME)
	@echo "\033[0;31m Compiled !!\033[0m"

bonus : libft $(NAME_B)
	@echo "\033[0;31m Compiled !!\033[0m"

$(NAME)	:  $(OBJECTS) 
	@echo "\033[0;31m CUB3D is compiling ...\033[0m"
	@$(CC) $(CFLAGS) $(OBJECTS) -Llibft -lft   -lmlx -lm -lX11 -lXext -o $(NAME)


$(NAME_B) :  $(OBJECTS_B) 
	@echo "\033[0;31m CUB3D_BONUS is compiling ...\033[0m"
	@$(CC) $(CFLAGS) $(OBJECTS_B) -o $(NAME_B) -Llibft -lft  -lmlx -lm -lX11 -lXext
libft:
	@$(MAKE) -C libft -s
clean : 
	@rm -rf $(OBJECTS) $(OBJECTS_B)
	@$(MAKE) clean -C libft -s

fclean : clean
	@rm -rf $(NAME) $(NAME_B)
	@$(MAKE) fclean -C libft -s
	@echo "\033[0;32m all clean \033[0m"

re : fclean all

.PHONY : all clean fclean re libft

.SILENT : $(OBJECTS) $(OBJECTS_B)
