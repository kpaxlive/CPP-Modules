SRCS = megaphone.cpp

NAME = megaphone

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

RM = rm -f

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

