NAME = libftprintf.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRCS =  ft_printf.c \
		print_c_and_s.c \
		print_d_and_i.c \
		print_p.c \
		print_u.c \
		print_x_and_X.c \
		ft_convert.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) 	

fclean: clean
	$(RM) $(NAME)

re: fclean all