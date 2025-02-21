SRC	=		ft_atoi.c	\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c	\
			ft_memset.c	\
			ft_bzero.c	\
			ft_memcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c	\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_strcmp.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_strnstr.c	\
			ft_strdup.c	\
			ft_substr.c	\
			ft_calloc.c	\
			ft_memmove.c	\
			ft_split.c	\
			ft_strjoin.c	\
			ft_strlcpy.c	\
			ft_strtrim.c	\
			ft_itoa.c	\
			ft_striteri.c	\
			ft_putstr_fd.c	\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_strmapi.c	\
			ft_lstnew.c	\
			ft_lstadd_front.c \
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c	\
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstmap.c \
			ft_lstiter.c	\
			get_next_line.c	\
			get_next_line_utils.c	\
			ft_printf.c	\
			ft_printf_utils.c

OBJ	= $(SRC:%.c=$(OBJ_D)%.o)

HEADER	= includes/libft.h

HEAD_D	= .

NAME	= libft.a

OBJ_D	= obj/

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_D) $(OBJ) Makefile includes/libft.h includes/get_next_line.h includes/ft_printf.h
		ar rcs $(NAME) $(OBJ)

$(OBJ):	$(OBJ_D)%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJ_D):
	@mkdir -p $(OBJ_D)

clean:
		@rm -rf $(OBJ) $(OBJ_BONUS) $(OBJ_D)
		@echo "C'est tout prop' !"

fclean: clean
		@rm -f $(NAME)
		@echo "C'est tout prop' mais mieux !!"

re: fclean all

.PHONY: all bonus clean fclean re