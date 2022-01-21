CFILES = ./outils/conditions/ft_is_flag.c ./outils/conditions/ft_is_specifier.c ./outils/list/ft_add_case.c \
./outils/list/ft_add_node_back.c ./outils/list/ft_creat_node.c ./outils/list/ft_get_node_by_id.c ./outils/list/ft_lstiter.c \
./outils/specifiers/ft_c_specifier.c ./outils/specifiers/ft_d_specifier.c ./outils/specifiers/ft_p_specifier.c \
./outils/specifiers/ft_s_specifier.c ./outils/specifiers/ft_x_specifier.c \
./outils/string/ft_atoi.c ./outils/string/ft_itoa.c ./outils/string/ft_strchr.c ./outils/string/ft_strdup.c \
./outils/string/ft_strjoin.c ./outils/string/ft_strjoinl.c ./outils/string/ft_strlcat.c ./outils/string/ft_strlcpy.c \
./outils/string/ft_strlen.c ./outils/string/ft_substr.c ./outils/ft_join_flags.c ./outils/ft_fill.c ./outils/ft_short_hexa_converter.c \
./outils/ft_for_hash_flag.c ft_printf.c ft_printf_outils.c

OFILES = ${CFILES:.c=.o}
CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME = libftprintf.a

all : ${NAME}

%.o: %.c ft_printf.h ft_printf_outils.h
	$(CC) $(CFLAGS) -o $@ -c $<

${NAME} : ${OFILES}
	ar -crs  $@ $^

bonus : ${NAME}

clean :
	rm -f ${OFILES} 

fclean : clean
	rm -f ${NAME}

re : fclean all
