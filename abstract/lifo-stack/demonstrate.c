/*
 * demonstrate.c
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


#include <stdio.h>
#include <string.h>
#include "item.h"
#include "array-llist.h"


int main(int argc, char **argv)
{
	/* LIFO stack implementation
	 * The internal linked list is not exposed.
	 */
	char *a = argv[1];
	int i, N = strlen(a);

	stackInit();
	for (i = 0; i < N; i++) {
		if ((a[i] >= '0') && (a[i] <= '9')) {
			stackPush(charToInt(a[i]));
		}
		if (a[i] == '+') {
			stackPush(stackPop() + stackPop());
		}
		if (a[i] == '-') {
			int x = stackPop();
			int y = stackPop();
			printf("%d / %d\n", y, x);
			stackPush(y - x);
		}
		if (a[i] == '*') {
			stackPush(stackPop() * stackPop());
		}
		if (a[i] == '/') {
			int x = stackPop();
			int y = stackPop();
			printf("%d / %d\n", y, x);
			if (x != 0) stackPush((int) (y / x));
		}
	}
	printf("%d \n", stackPop());
	return 0;
}
