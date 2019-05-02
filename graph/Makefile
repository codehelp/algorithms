all:
	gcc -lm vertices.c graph.c -o vertices

check:
	gcc -lm mintest.c vertices.c -o mintest
	./mintest

clean:
	$(RM) vertices mintest *.o vertices.h.gch
