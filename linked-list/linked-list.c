/*
 * linked-list.c
 * 
 * Copyright 2019 Neil Williams <linux@codehelp.co.uk>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "linked-list.h"

// FIXME: why is a fixed length list of nodes required?
llink initialised_list;

llink allocNode(int value) {
	llink x = malloc(sizeof *x);
	x->item = value;
	x->next = x;
	return x;
}

void freeNode(llink x) {
	free(x);
}

void initNodes(int N) {
	int i;
	// FIXME: clarify the pointer arithmetic
	initialised_list = malloc((N+1)*(sizeof *initialised_list));
	for (i = 0; i < N + 1; i++)
		initialised_list[i].next = &initialised_list[i+1];
	initialised_list[N].next = NULL;
}

llink newNode(int item_value) {
	llink x = deleteNext(initialised_list);
	x->item = item_value;
	x->next = x;
	return x;
}

void forgetNode(llink x) {
	insertNext(initialised_list, x);
}

void insertNext(llink x, llink t) {
	t->next = x->next;
	x->next = t;
}

llink deleteNext(llink x) {
	llink t = x->next;
	x->next = t->next;
	return t;
}

llink Next(llink x) {
	return x->next;
}

int Item(llink x) {
	return x->item;
}

void demonstrate_alloc_nodes(int N, int M) {
	int i;
	Node t, x;
	for (i = 2, x = allocNode(1); i <= N; i++) {
		t = allocNode(i);
		insertNext(x, t);
		x = t;
	}
	while (x != Next(x)) {
		for (i = 1; i < M; i++) x = Next(x);
		freeNode(deleteNext(x));
	}
	printf("%d\n", Item(x));
}

void demonstrate_init_list(int N, int M) {
	int i;
	Node t, x;
	initNodes(N);
	for (i = 2, x = newNode(1); i <= N; i++) {
		t = newNode(i);
		insertNext(x, t);
		x = t;
	}
	while (x != Next(x)) {
		for (i = 1; i < M; i++) x = Next(x);
		forgetNode(deleteNext(x));
	}
	printf("%d\n", Item(x));
}

int main(int argc, char **argv)
{
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	llink t = malloc(sizeof *t);
	llink x = t;
	t->item = 1;
	t->next = t;
	for (i = 2; i <= N; i++) {
		x->next = malloc(sizeof *x);
		x = x->next;
		x->item = i;
		x->next = t;
	}
	llink start = x;

	int count = 1;
	x = t->next;
	while (x->item != t->item) {
		count++;
		x = x->next;
	}
	printf("count: %d\n", count);
	x = t;

	 x = start;
	printf("start: %d\n", x->item);
	while (x != x->next) {
		for (i = 1; i < M; i++) x = x->next;
		x->next = x->next->next; N--;
	}
	printf("%d\n", x->item);
	free(x);

	long int start_time = time(0);
	printf("%ld\n", time(0) - start_time);
	demonstrate_init_list(10 ^ 8, 2);
	printf("%ld\n", time(0) - start_time);
	demonstrate_alloc_nodes(10 ^ 8, 2);
	printf("%ld\n", time(0) - start_time);
	return 0;
}

