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
