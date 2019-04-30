all:
	gcc union-find.c algorithms.c -o algorithm

check:
	gcc mintest.c union-find.c -o mintest
	./mintest

clean:
	$(RM) algorithm mintest *.o
