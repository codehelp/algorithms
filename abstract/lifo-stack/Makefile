all:
	gcc -g array-llist.c demonstrate.c -o llist

check:
	gcc -lm mintest.c array-llist.c -o mintest
	./mintest

clean:
	$(RM) llist mintest *.o *.gch
