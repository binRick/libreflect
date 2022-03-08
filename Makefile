CFLAGS += -std=c99 -g -lm -luv -lcurl
CFLAGS += -I ./include -I ./src

all: clean prep test


prep:
	mkdir -p bin

test1: tests/test1.c
	$(CC) -o ./bin/$@ $(CFLAGS) $^

test2: tests/test2.c
	$(CC) -o ./bin/$@ $(CFLAGS) $^

test: test1 test2
	./bin/test1
	./bin/test2

clean:
	rm -rf bin
