CFILES = ft_printf.c ft_printf_outils.c
OFILES = ${CFILES:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
NAME = libftprintf.a
all : ${NAME}
	gcc $(CFLAGS) ${CFILES}
${NAME} : ${OFILES} 
	ar -crs $@ $^
clean :
	rm -f ${OFILES} 
fclean : clean
	rm -f ${NAME}
re : fclean all
