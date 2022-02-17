NAME ?= libft.a

SRC := \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_putstr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_calloc.c \
	ft_split.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putnbr_fd.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_strnstr.c \
	ft_putchar.c \
	ft_strndup.c \
	ft_strcmp.c \
	ft_swap.c \
	get_next_line.c
	
SRC_BONUS := \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

src := $(wildcard *.c)
no_files := $(words $(src))
obj := $(src:.c=.o) $(pfsrc:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

CC		= 	gcc
CFLAGS ?= -Wall -Wextra -Werror -O3
RM		= 	rm -f

all:	$(NAME)

$(NAME): $(obj)
	@echo "Total file compiled: ${no_files}"
	@ar rc $(NAME) $(obj)
	@$(RM) $(obj)

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o  $@

bonus:	$(SRC_BONUS)
		@$(CC) $(CFLAGS) -c $^
		@ar ru $(NAME) $^
		@ranlib $(NAME)
		@$(RM) $(OBJ_BONUS)
clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all bonus

.PHONY: all fclean re bonus clean
