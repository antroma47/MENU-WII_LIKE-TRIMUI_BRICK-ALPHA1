CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./include
LDFLAGS = -lSDL2 -lSDL2_image -lm
TARGET = trimui-wii-menu
SOURCES = src/main.c src/render.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✓ Build OK: $@"

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

.PHONY: all clean
