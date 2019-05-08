/*
 * array-llist.c
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
#include "item.h"
#include "array-llist.h"

lList stackNewItem(Item item, lList next) {
	/* TODO: handle lList x == NULL
	 * if malloc fails.
	 * return errval instead of x. */
	lList x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}

static lList head;

void stackInit(void) {
	head = NULL;
}

int stackEmpty(void) {
	/* empty stack is simply an empty linked list */
	return head == NULL;
}

int stackPush(Item item) {
	/* Needs a check: if (item == errval) {return errval;}
	 * once errval is defined.
	 */
	head = stackNewItem(item, head);
	return 0;
}

Item stackPop(void) {
	/* No protection from stackEmpty
	 * stackPop on an empty list will seg fault.
	 * A full API would need to restrict one specific
	 * Item value to a reserved error state which could
	 * be returned: if (stackEmpty()) {return errval};
	 */
	Item item = head->item;
	lList t = head->next;
	free(head);
	head = t;
	return item;
}

int charToInt(char a) {
	/* Convert char '<digit>' to int <digit>
	 * (atoi requires null terminated const char *)
	 * This function can take const char * [index]
	 */
	int t = 0;
	t = 10 * t + (a - '0');
	return t;
}
