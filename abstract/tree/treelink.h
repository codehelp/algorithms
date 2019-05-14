/*
 * treelink.h
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

typedef struct node *Tlink;

/* It would be convenient to not use int but
 * the Item needs an equality operator and
 * using char causes problems with QueueFill.
 */
typedef int Item;

struct node {
	Item item;
	Tlink parent;
	Tlink left;
	Tlink right;
};

void QueueInit(void);

int QueueEmpty(void);

Tlink QueueNewItem(Item, Tlink, Tlink);

Tlink QueueFill(Item [], int, int);

void QueuePut(Tlink);

Tlink QueueGet(void);

void recurseTree(Tlink, void (*)(Tlink));

void traverseTree(Tlink, void(*)(Tlink));

void recurseDraw(Tlink, int);
