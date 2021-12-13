hello:hello.o
	gcc -o hello hello.o
hello.o: hello.c
	gcc -o hello.o -c hello.c
.PHONY:clean
clean:
	rm hello 
	rm hello.o
