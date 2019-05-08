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

#include "item.h"

/* Convert char '<digit>' to int <digit>
 * (atoi requires const char *)
 * May produce unexpected results if char is not within 0 to 9
 * Only used by the demonstration program to handle argv[]
 */
int charToInt(char a);

/* struct used to create a linked list */
typedef struct StackNode * lList;
struct StackNode {
	Item item;
	lList next;
};

lList stackNewItem(Item item, lList next);

void stackInit(void);

int stackEmpty(void);

int stackPush(Item item);

Item stackPop(void);
