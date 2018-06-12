flags = -Wall

all: build rkmatcher

rkmatcher: build/main.o build/function.o build/string.o
	gcc $(flags)  build/main.o build/function.o build/string.o -o rkmatcher

build/main.o: src/main.c
	gcc $(flags) -c src/main.c -o build/main.o

build/string.o: src/string.c
	gcc $(flags) -c src/string.c -o build/string.o

build/function.o: src/function.c
	gcc $(flags) -c src/function.c -o build/function.o

build:
	mkdir -p build

.PHONY: clean

clean:
	rm -rf build