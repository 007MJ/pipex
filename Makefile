NAME     = pipex
CC       = gcc
CFLAG    = -Wall -Werror -Wextra
RM       = rm -fr
SRC      = src/main.c src/get_next_line_utils.c src/get_next_line.c src/ft_strncmp.c src/stilsame.c
OBJSFILE = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJSFILE)
	$(CC) -o $(NAME) $(OBJSFILE)

%.o : %.c
	$(CC) $(CFLAG) -o $@ -c $^

clean :
	$(RM) $(OBJSFILE)

fclean: clean
	$(RM) $(NAME)

re : all clean flcean
