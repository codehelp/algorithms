/*
 * union-find.c
 *
 * Copyright 2019 Neil Williams <codehelp@debian.org>
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
#define N 10
#define DEBUG 1


// https://stackoverflow.com/questions/41928145/why-arent-scanf-n-n-and-scanf-nc-clearing-a-hanging-newli

int check(const int array[], int n)
{
	const int a0 = array[0];

	for (int i = 1; i < n; i++)
	{
		if (array[i] != a0) {
			return 1;
		}
	}
	return 0;
}

void setup_program_1(int id[]){
	int i;
	for (i=0; i < N; i++) id[i] = i;
	for (i = 0; i < N; i++) {
		printf("%d ", id[i]);
	}
	printf("\n");
}

int program_1_1(int p, int q, int id[])
{
	int i;
	int t;
	if (id[p] == id[q]) {
# ifdef DEBUG
		printf("\t\tFound: ");
		for (i = 0; i < N; i++) {
			if (id[i] == q) printf("%d ", i);
			if (id[i] == p) printf("%d ", i);
		}
		printf("\n");
# endif
		return 2;
	}
	t = id[p];
	for (i=0; i < N; i++) {
		if (id[i] == t) id[i] = id[q];
	}
	for (i = 0; i < N; i++) {
		printf("%d ", id[i]);
	}
	printf("\n");
	if (check(id, N) == 0) {
		printf("Connections complete\n");
		return 0;
	}
	printf("New: %d %d\n", p, q);
	return 1;
}


int
program_1_2(int p, int q, int id[])
{
	int i, j, t;
	for (i = p; i != id[i]; i = id[i]);
	for (j = q; j != id[j]; j = id[j]);
	if (i == j) return 2;
	id[i] = j;
	for (t = id[p], i=0; i < N; i++) {
		if (id[i] == t) id[i] = id[q];
	}
	for (i = 0; i < N; i++) {
		printf("%d ", id[i]);
	}
	printf("\n");
	printf("\t%d %d\n", p, q);
	return 1;
}

void setup_program_1_3(int id[], int sz[]){
	// sz keeps the number of nodes in the tree for each id[i] == i
	int i;
	// reset id to start with a sequential integer array using sz
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
}

int
program_1_3(int p, int q, int id[], int sz[])
{
	/* Program 1.3 */
	int i, j;
	// loop through id, incrementing based on the initial values within id
	for (i = p; i != id[i]; i = id[i]);
	for (j = q; j != id[j]; j = id[j]);
	// i is the position of p in id
	// j is the position of q in id
	if (i == j) return 2;
	// make a union, smaller into larger
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
	} else {
		id[j] = i;
		sz[i] += sz[j];
	}
	printf(" %d %d\n", p, q);
	return 0;
}
