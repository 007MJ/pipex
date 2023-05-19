NAME     = pipex
CC       = gcc
CFLAG    = -Wall -Werror -Wextra
RM       = rm -fr
SRC      = main.c
OBJSFILE = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJSFILE)
	$(CC) -o $(NAME) $(OBJSFILE)

$(OBJSFILE) : $(SRC)
	$(CC) $(CFLAG) -o $@ -c $^

clean :
	$(RM) $(OBJSFILE)

fclean: clean
	$(RM) $(NAME)

re : all clean flcean