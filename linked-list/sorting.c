/*
 * sorting.c
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

llink reverse(llink x) {
	/*
	 * reverse the links in the list
	 * maintain a pointer to what has already been processed
	 * maintain a pointer to the portion not yet processed
	 * change the node link to point to the previous node
	 */
	llink t, y = x, r = NULL;
	while (y != NULL) { // to the end of the list
		t = y->next;  // store the portion not yet processed
		y->next = r; // change link direction
		r = y; // store the completion point
		y = t; // move on to the next node in the original list
	}
	return r;
}

int main(int argc, char **argv)
{
	int i, N = atoi(argv[1]);
	struct node heada, headb;
	llink t, u, x, a = &heada, b, s, r;
	srand(time(0));  // ensure different numbers on each run
	printf("Generated ");
	for (i = 0, t = a; i < N; i++) {
		t->next = malloc(sizeof *t);
		t = t->next;
		t->next = NULL;
		t->item = rand() % 1000;
		printf("%03d", t->item);
		if (i != N -1) printf(", ");
	}
	printf("\n");

	b = &headb;
	b->next = NULL;
	s = b;

	// insertion sort
	for (t = a->next; t != NULL; t = u) {
		u = t->next;
		for (x = b; x->next != NULL; x = x->next) {
			if (x->next->item > t->item) {
				printf("Found insertion point for "
					"%03d before %03d\n",
					t->item, x->next->item);
				break;
			}
		}
		t->next = x->next;
		x->next = t;
	}
	s = s->next;
	printf("\n\nSorted: \n");
	for (i = 0, t = s; i < N; i++) {
		printf("%03d\n", t->item);
		t = t->next;
	}
	printf("\n\nReversed:\n");
	r = reverse(b);
	for (i = 0, t = r; i < N; i++) {
		printf("%03d\n", t->item);
		t = t->next;
	}
	return 0;
}
