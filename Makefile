NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

RM = rm -rf

SRC = 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) printf.h
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean 