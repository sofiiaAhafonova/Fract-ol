NAME = fractol

SRC_PATH = src
SRC_NAME =  main.c init_env.c remove_env.c key_hooks.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -Iinclude -Ilibmlx/

LDFLAGS =
LDLIBS =  -lXext -lX11 -lm


SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) libmlx/libmlx_Linux.a
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of Fractol:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Fractol: Removing Objs"

fclean: clean
	@rm -f $(NAME)
	@echo "Fractol : Removing Fractol"

re: fclean all

.PHONY: all clean fclean re
