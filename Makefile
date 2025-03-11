NAME = pipex
CC = cc
CFLAGS	=	-Wall -Wextra -Werror -g3

HEAD = includes/pipex.h
SRC_DIR = src/
OBJ_DIR = objs/

SRC_FILES =	main.c	\
			pather.c	\
			incubator.c	\
			fd_utils.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

LIBFT_DIR = libft/

all:	lib $(NAME)

lib:
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Libft compiled !"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c ./libft/includes/libft.h ./libft/libft.a | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean --silent -C $(LIBFT_DIR)

fclean: clean
	@echo "Clean all binary"
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
