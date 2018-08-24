CC := gcc
FLAGS := -Wall -Wextra -Werror
NAME :=  libftprintf.a

SRC_DIR	:= ./src
INC_DIR	:= ./includes
LIB_DIR := ./src/libft

INCS	:=	-I $(INC_DIR)

OBJ_DIR1	:= ./obj1
OBJ_DIR2	:= ./obj2

SRC_FT_PRINTF	:=	ft_printf.c \
					itoa_base.c \
					get.c \
					get_number.c \
					join.c \
					parsing/parsing.c \
					parsing/parse_flags.c \
					parsing/parse_argument.c \
					parsing/filtration.c \
					type/type_char.c \
					type/type_decimal.c \
					type/type_else.c \
					type/type_hexidecimal.c \
					type/type_octal.c \
					type/type_pointer.c \
					type/type_n.c \
					type/type_string.c \
					type/type_unsigned.c \
					type/type_wchar.c \
					type/type_wchar_string.c

SRC_LIBFT		:=	ft_abs.c ft_atoi.c ft_bzero.c ft_getleni.c ft_isalnum.c \
					ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
					ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
					ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c \
					ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
					ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
					ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
					ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
					ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
					ft_strreverse.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
					ft_tabsymb.c ft_tolower.c ft_toupper.c ft_memjoin.c

SRCS1			=	$(addprefix $(SRC_DIR)/, $(SRC_FT_PRINTF))

SRCS2			=	$(addprefix $(LIB_DIR)/, $(SRC_LIBFT))

OBJS1			=	$(addprefix $(OBJ_DIR1)/, $(SRC_FT_PRINTF:.c=.o))

OBJS2			=	$(addprefix $(OBJ_DIR2)/, $(SRC_LIBFT:.c=.o))

# DBG MESSAGE
SUCCESS			:=	$(C_GOOD)SUCCESS$(C_NO)
OK				:=	$(C_OK)OK$(C_NO)

.PHONY: clean all re fclean

all: dirs $(NAME)

$(NAME): $(OBJS1) $(OBJS2)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[34;1mCompiling\033[0m" "\033[33;1m" [ $(NAME) ] "\033[0m" "\033[32;1m" $(SUCCESS) "\033[0m"

dirs:
	@mkdir -p obj1/parsing obj1/type obj2

$(OBJ_DIR1)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) $(INCS) -c -o $@ $<
	@echo "\033[37;1mLinking\033[0m" "\033[33;1m" [ $< ] "\033[0m" "\033[32;1m" $(OK) "\033[0m"

$(OBJ_DIR2)/%.o: $(LIB_DIR)/%.c
	@$(CC) $(FLAGS) $(INCS) -c -o $@ $<
	@echo "\033[37;1mLinking\033[0m" "\033[33;1m" [ $< ] "\033[0m" "\033[32;1m" $(OK) "\033[0m"

clean:
	@rm -f $(OBJS1) $(OBJS2)
	@echo "\033[36;1mCleaning\033[0m" "\033[33;1m" [ $(NAME) ] "\033[0m" "\033[37;1m...\033[0m" "\033[32;1m" $(OK) "\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31;1mDelete\033[0m" "\033[33;1m" [ $(NAME) ] "\033[0m" "\033[32;1m" $(OK) "\033[0m"

re: fclean all
