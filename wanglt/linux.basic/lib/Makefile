.PHONY: clean

hello: main.o
	gcc -o $@ $^ -L./lib/ -lhello
main.o:main.c
	gcc -o $@ -c $^

clean:
	rm hello main.o
