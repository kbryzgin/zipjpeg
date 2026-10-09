# building configuration

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude

TARGET = zipjpeg
SRCS = src/main.c src/zip_parser.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
