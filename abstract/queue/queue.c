/*
 * queue.c
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
#include "item.h"
#include "queue.h"

/* head is used when removing nodes for get
 * tail is used when adding nodes to the end with put */
static Qlink head, tail;

Qlink newItem(Item item, Qlink next) {
	Qlink x = malloc(sizeof * x);
	x->item = item;
	x->next = next;
	return x;
}

void QueueInit(void) {
	head = NULL;
}

int QueueEmpty(void) {
	return head == NULL;
}

void QueuePut(Item item) {
	/* FIFO - so put new items at the end of the queue */
	if (head == NULL) {
		/* first entry */
		head = (tail = newItem(item, head));
		return;
	}
	tail->next = newItem(item, tail->next);
	tail = tail->next;
}

Item QueueGet(void) {
	/* Return the item at the head of the Queue:
	 * unhook the first node from the head
	 * assign head to what was the second node
	 * free the dangling node
	 * TODO: handle a call to an empty list.
	 * (would be easier if Item was not typedef int)
	 */
	Item item = head->item;
	Qlink t = head->next;
	free(head);
	head = t;
	return item;
}
