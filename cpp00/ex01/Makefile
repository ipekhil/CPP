CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = contact.cpp phonebook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = phonebook
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
all: $(TARGET)
