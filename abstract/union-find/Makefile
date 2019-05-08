all:
	gcc -g union-find.c demonstrate.c -o union-find

check:
	gcc -lm mintest.c union-find.c -o mintest
	./mintest

clean:
	$(RM) union-find mintest *.o *.gch
