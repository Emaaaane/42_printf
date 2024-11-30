NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_helpers_num.c ft_helpers_str.c

OBJ = $(SRC:.c=.o)

AR = ar -rc

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean 