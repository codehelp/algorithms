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
#include "linked-list.h"

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
	return 0;
}

