.PHONY:clean

libhello.a:hello.o
	ar rcs $@ $^
hello.o: hello.c hello.h
	gcc -o $@ -c $<

clean:
	rm hello.o libhello.a
