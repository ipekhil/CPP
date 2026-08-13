NAME = bureaucrat
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Bureaucrat.cpp Form.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
all: $(NAME)
