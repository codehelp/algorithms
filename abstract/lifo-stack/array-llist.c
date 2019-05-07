/*
 * stack.c
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

llist NEW(Item item, llist next) {
	llist x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}

static llist head;

void STACKinit(void) {
	head = NULL;
}

int STACKempty(void) {
	return head == NULL;
}

void STACKpush(Item item) {
	head = NEW(item, head);
}

Item STACKpop(void) {
	Item item = head->item;
	llist t = head->next;
	free(head);
	head = t;
	return item;
}

int convert_char(char a) {
	int t = 0;
	t = 10 * t + (a - '0');
	return t;
}
