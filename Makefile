NAME     = pipex
CC       = gcc
CFLAGS    = -Wall -Werror -Wextra -g -fsanitize=address
# -g -fsanitize=address
RM       = rm -fr
SRC      = src/main.c src/ft_strncmp.c src/ft_stilsame.c src/ft_split.c src/pathcmd.c src/pathname.c src/ft_strlen.c \
			src/test_cmd.c src/missargv.c src/notfound.c src/ft_substr.c src/phase1.c src/pipe_close.c
OBJSFILE = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJSFILE)
	$(CC) $(CFLAGS) $(OBJSFILE) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	$(RM) $(OBJSFILE)

fclean: clean
	$(RM) $(NAME)

re : fclean all
