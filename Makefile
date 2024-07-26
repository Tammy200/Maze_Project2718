CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I./include -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -lSDL2 -lSDL2_image -lm
SRC = src/main.c src/raycasting.c src/map_parser.c src/textures.c
OBJ = $(SRC:.c=.o)
TARGET = maze

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

