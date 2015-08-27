NAME=libfts.a
CASM=~/.brew/Cellar/nasm/2.11.08/bin/nasm
ASMFLAGS=-f macho64 --prefix _
ASMSRC_NAME=ft_bzero.s\
ft_strcat.s\
ft_isalpha.s\
ft_isdigit.s\
ft_isalnum.s\
ft_isprint.s\
ft_isascii.s\
ft_toupper.s\
ft_islower.s\
ft_isupper.s\
ft_tolower.s\
ft_strlen.s\
ft_puts.s\
ft_memset.s\
ft_memcpy.s\
ft_strdup.s\
ft_memalloc.s\
ft_cat.s\
ft_putstr.s
OBJ_NAME=$(ASMSRC_NAME:.s=.o)

SRC_PATH=./src/
OBJ_PATH=./obj/
INC_PATH=./includes/

SRC = $(addprefix $(SRC_PATH),$(ASMSRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

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
