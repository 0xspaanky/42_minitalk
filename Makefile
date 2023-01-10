CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./utils

SRC_C = $(SRC_PATH)/ft_printf.c $(SRC_PATH)/ft_printf_fcns.c $(SRC_PATH)/ft_printf_fcns_II.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_isstrdigit.c $(SRC_PATH)/ft_strlen.c client.c 
SRC_S = $(SRC_PATH)/ft_printf.c $(SRC_PATH)/ft_printf_fcns.c $(SRC_PATH)/ft_printf_fcns_II.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_isstrdigit.c $(SRC_PATH)/ft_strlen.c server.c
SRC_C_B = $(SRC_PATH)/ft_printf.c $(SRC_PATH)/ft_printf_fcns.c $(SRC_PATH)/ft_printf_fcns_II.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_isstrdigit.c $(SRC_PATH)/ft_strlen.c client_bonus.c 
SRC_S_B = $(SRC_PATH)/ft_printf.c $(SRC_PATH)/ft_printf_fcns.c $(SRC_PATH)/ft_printf_fcns_II.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_isstrdigit.c $(SRC_PATH)/ft_strlen.c server_bonus.c 

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C_B = $(SRC_C_B:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)

NAME_C = client
NAME_S = server
NAME_C_B = client_bonus
NAME_S_B = server_bonus

RM = rm -f

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
$(NAME_S) : $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)

bonus: $(OBJ_C_B) $(OBJ_S_B)

$(NAME_C_B) : $(OBJ_C_B)
	$(CC) $(CFLAGS) $(OBJ_C_B) -o $(NAME_C_B)
$(NAME_S_B) : $(OBJ_S_B)
	$(CC) $(CFLAGS) $(OBJ_S_B) -o $(NAME_S_B)

clean:
	$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_S_B) $(OBJ_C_B)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S) $(NAME_S_B) $(NAME_C_B)

re: fclean all