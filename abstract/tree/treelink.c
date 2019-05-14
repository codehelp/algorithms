/*
 * treelink.c
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
#include "treelink.h"

void traverseTree(Tlink head, void(*visit)(Tlink)) {
	/* copies the structure of the tree into a stack
	 * for processing. */
	
	/* TODO: array-llist.c needs modification to return
	 * the node, not the item.
	 */
	QueueInit();
	while (!QueueEmpty()) {
		(*visit)(head = QueueGet());
		if (head->left != NULL) QueuePut(head->left);
		if (head->right != NULL) QueuePut(head->right);
	}
}

int recurseCount (Tlink head) {
	if (head == NULL) return 0;
	return recurseCount(head->left) + recurseCount(head->right) + 1;
}

int recurseHeight (Tlink head) {
	int u, v;
	if (head == NULL) return -1;
	u = recurseHeight(head->left);
	v = recurseHeight(head->right);
	if (u > v) return u + 1;
	else return v + 1;
}

void printNode(Item item, int h) {
	int i;
	for (i = 0; i < h; i++) printf(" ");
	/* Item from the list is int but markers from recurseDraw are char */
	if (item < 10) item += '0';
	printf("%c\n", (char) item);
}

void recurseDraw(Tlink x, int h) {
	/* initialise drawing with h = 0 */
	if (x == NULL) {
		printNode('*', h);
		return;
	}
	recurseDraw(x->right, h + 1);
	printNode(x->item, h);
	recurseDraw(x->left, h + 1);
}
