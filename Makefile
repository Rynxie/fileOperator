CC=gcc

CFLAGS=-I./Core/Inc

SOURCES=$(wildcard ./Core/Src/*.c)

OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=./Build/app

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	mkdir -p Build
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ./Core/Src/*.o $(EXECUTABLE)
	rm -r ./Build