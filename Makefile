NAME=libftasm.a
NAME_TEST=test_lib
CC=gcc
CASM=nasm
CFLAGS=-Wall -Wextra -Werror
ASMFLAGS=-f elf64
CSRC_NAME=main.c
ASMSRC_NAME=ft_bzero.s\
ft_strcat.s\
ft_isalpha.s\
ft_isdigit.s\
ft_isalnum.s\
ft_isprint.s\
ft_isascii.s
OBJ_NAME=$(ASMSRC_NAME:.s=.o)
COBJ_NAME=(CSRC_NAME:.c=.o)

SRC_PATH=./src/
OBJ_PATH=./obj/
INC_PATH=./includes/

SRC = $(addprefix $(SRC_PATH),$(ASMSRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
COBJ = $(addprefix $(OBJ_PATH),$(COBJ_NAME))

all:$(NAME)

clean:
	rm -rf $(OBJ_PATH)
fclean:clean
	rm -f $(NAME)
re:fclean all

test:all $(NAME_TEST)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.s
	@mkdir -p $(OBJ_PATH)
	$(CASM) $(ASMFLAGS) $(INC) $< -o $@

#$(OBJ_PATH)%.o:$(SRC_PATH)%.c
#	mkdir -p $(OBJ_PATH)
#	$(CC) $(CFLAGS) $(INC) -c $< -o $@

#$(NAME)_TEST:$(COBJ)
#	$(CC) $(CFLAGS) $(COBJ) -o $(NAME_TEST)
