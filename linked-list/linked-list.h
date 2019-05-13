/*
 * linked-list.h
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

typedef struct node *llink;

struct node {
	int item;
	llink next;
};

typedef llink Node;

llink allocNode(int, llink);
void freeNode(llink x);
void insertNext(llink, llink);
llink deleteNext(llink);
llink Next(llink);
int Item(llink);

/* recursive routines */
int count (llink);
void traverse(llink, void (*)(llink));
void traverseBack(llink, void (*)(llink));
llink delete(llink, int);


/* FIXME: remove? */
void initNodes(int);
llink newNode(int);
void forgetNode(llink);
