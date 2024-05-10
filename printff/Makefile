NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c \
	   ft_putchar_fd.c \
	   ft_putnbr_fd.c \
	   ft_putnbr_fd_hex.c \
	   ft_putnbr_fd_uns.c \
	   ft_putptr_fd.c \
	   ft_putstr_fd.c

HEAD = ft_printf.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean :
	@rm -f $(OBJS)
	make clean -C ./libft

fclean : clean 
	@rm -f $(NAME)
	@rm -f libft.a
	@rm -f libftprintf.a
	make fclean -C libft

re : fclean all

.PHONY: all re fclean clean
