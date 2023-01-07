CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./utils

SRC_C = $(SRC_PATH)/ft_printf.c $(SRC_PATH)/ft_printf_fcns.c $(SRC_PATH)/ft_printf_fcns_II.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_isstrdigit.c $(SRC_PATH)/ft_strlen.c client.c 
SRC_S = $(SRC_PATH)/ft_printf.c $(SRC_PATH)/ft_printf_fcns.c $(SRC_PATH)/ft_printf_fcns_II.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_isstrdigit.c $(SRC_PATH)/ft_strlen.c server.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

NAME_C = client

NAME_S = server

RM = rm -f

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
$(NAME_S) : $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)

clean:
	$(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S)

re: fclean all