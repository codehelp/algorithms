/*
 * union-find.c
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
#include "union-find.h"

static int *id, *sz;

void UFinit(int N) {
	int i;
	id = malloc(N * sizeof(int));
	sz = malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
}

static int find(int x) {
	int i = x;
	while (i != id[i]) {
		i = id[i];
	}
	return i;
}

int UFfind(int p, int q) {
	return find(p) == find(q);
}

int UFunion(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i == j) return 2;
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
	} else {
		id[j] = i;
		sz[i] += sz[j];
	}
	return 0;
}
