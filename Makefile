CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SOURCES = my_mouse.c c/*.c
TARGET = my_mouse
CC = gcc

$(TARGET) : $(SOURCES)
	@$(CC) $(CFLAGS) -o $@ $^

.PHONY: fclean

fclean: clean

clean:
	@rm -rf $(TARGET)

make re:
	@rm -rf $(TARGET)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)