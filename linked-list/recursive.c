/*
 * recursive.c
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

typedef struct {int size; int value;} Item;
  
/* sentinel value for the arrays of known items */
int unknown = -1;

/* knapsack
 * Find the items which will provide the highest
 * collective value for the available size of the sack.
 * This example requires that there are sufficient numbers of
 * each type of item for all permutations.
 * Once an optimal solution is found for a small sack, that
 * solution does not change if a larger sack has the same amount
 * of available space as that small sack after putting an item in
 * the larger sack.
 */
Item items[5];
Item itemKnown[20];
int maxKnown[20];

int knapsack(int M) {
	/* This method becomes ineffective for very large sacks
	 * due to the time required to compute optimal solutions
	 * for each smaller sack which could be contained in the largest
	 * sack. */

	int i, space, max, maxi, t, len;
	len = (int)(sizeof(items) / sizeof(Item));

	/* avoid repeating the recursion
	 * store any values already computed,
	 * i.e. for possible smaller sacks.
	 */
	if (maxKnown[M] != unknown) return maxKnown[M];

	for (i = 0, max = 0; i < len; i++) {
		if ((space = M - items[i].size) >= 0) {
			/* this item will fit */
			if ((t = knapsack(space) + items[i].value) > max) {
				/* The maximum value once this item is in the
				 * sack is higher than the maximum obtained
				 * by any previous item being first in the sack. */
				max = t;
				maxi = i;
			}
		}
	}
	maxKnown[M] = max;
	itemKnown[M] = items[maxi];
	return max;
}

int main(int argc, char **argv)
{
	int M = 17;

	/* initialize */
	int len = (int)(sizeof(itemKnown) / sizeof(Item));
	for (int i = 0; i < len; i++) {
		maxKnown[i] = unknown;
	}
	Item a = {3, 4};
	items[0] = a;
	Item b = {4, 5};
	items[1] = b;
	Item c = {7, 10};
	items[2] = c;
	Item d = {8, 11};
	items[3] = d;
	Item e = {9, 13};
	items[4] = e;

	int res = knapsack(M);
	printf("Total: %d\n", res);
	while (M > 0) {
		printf("Size %d for value %d\n", itemKnown[M].size, itemKnown[M].value);
		M = M - itemKnown[M].size;
	}
	return 0;
}
