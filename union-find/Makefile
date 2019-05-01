all:
	gcc -lm union-find.c algorithms.c -o algorithm

check:
	gcc -lm mintest.c union-find.c -o mintest
	./mintest

clean:
	$(RM) algorithm mintest *.o union-find.h.gch
