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
#include "treelink.h"


/* head is used when removing nodes for get
 * tail is used when adding nodes to the end with put */
static Tlink head, tail;

void QueueInit(void) {
	head = NULL;
}

Tlink QueueNewItem(Item item, Tlink left, Tlink right) {
	Tlink newest = malloc(sizeof * newest);
	newest->item = item;
	newest->left = left;
	newest->right = right;
	newest->parent = NULL;
	return newest;
}

Tlink QueueFill(Item items[], int list_start, int list_end) {
	int m = (list_start + list_end) / 2;
	Item u, v;
	Tlink newest = QueueNewItem(items[m], NULL, NULL);
	if (list_start == list_end) return newest;
	newest->left = QueueFill(items, list_start, m);
	newest->right = QueueFill(items, m + 1, list_end);
	u = newest->left->item;
	v = newest->right->item;
	/* FIXME: relies on the nature of Item */
	if (u > v) {
		newest->item = u;
	} else {
		newest->item = v;
	}
	return newest;
}

int QueueEmpty(void) {
	return head == NULL;
}

void QueuePut(Tlink tnode) {
	/* FIFO - so put new items at the end of the queue */
	if (head == NULL) {
		/* first entry */
		head = tail = tnode;
		return;
	}
	/* unsorted tree, merely add to the end,
	 * arbitrarily on the left */
	tnode->parent = tail;
	tail->left = tnode;
}

Tlink QueueGet(void) {
	/* Return the item at the head of the Queue:
	 * unhook the first node from the head
	 * assign head to what was the second node
	 * return the old head - needs to be freed by the caller.
	 */
	Tlink old = head;
	old->left->parent = old->left;
	old->right->parent = NULL;

	Tlink t = old->left;
	head = t;

	return old;
}
