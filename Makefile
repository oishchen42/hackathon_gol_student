CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99 -O2
LDFLAGS = 

TARGET = game_of_life
OBJS = main.o life_simulate.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c life_simulate.h
	$(CC) $(CFLAGS) -c main.c

life_simulate.o: life_simulate.c life_simulate.h
	$(CC) $(CFLAGS) -c life_simulate.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
