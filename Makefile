All: bin/prog

prog: build/main.o
	gcc -Wall -Werror -o bin/prog build/main.o

main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o

.PHONY: clean
clean:
	rm -rf build/*.o