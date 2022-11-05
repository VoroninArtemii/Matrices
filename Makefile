clean:
	rm -rf main *.o
main: main.c library.c
	c99 main.c library.c -o main
