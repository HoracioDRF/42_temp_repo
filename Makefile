NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf/ft_printf.c \
       ft_printf/ft_print_char.c \
       ft_printf/ft_print_string.c \
       ft_printf/ft_print_number.c \
       ft_printf/ft_print_unsigned.c \
       ft_printf/ft_print_hex.c \
       ft_printf/ft_print_pointer.c \
       ft_printf/ft_utils.c \
       ft_printf/ft_itoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -Ift_printf -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
