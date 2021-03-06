/*
 * vertices.c
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
#include <stdlib.h>
#include "vertices.h"

void setup_matrix(int adj_matrix[V][V]) {
	int i, j;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			adj_matrix[i][j] = 0;
	// all points point to themselves
	for (i = 0; i < V; i++) adj_matrix[i][i] = 1;
}

void add_edge(int a, int b, int adj_matrix[V][V]) {
	/*
	 * Note: this is only about being adjacent.
	 * Calculation of paths longer than > 1 edge is not efficient.
	 * all defined points a bidirectional.
	 */
	adj_matrix[a][b] = 1;
	adj_matrix[b][a] = 1;
}

void output_matrix(int adj_matrix[V][V]) {
	int i, j;
	printf(" ");
	for (i = 0; i < V; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (i = 0; i < V; i++) {
		printf("%d ", i);
		for (j = 0; j < V; j++) {
			if (adj_matrix[i][j] == 1) printf("* ");
			if (adj_matrix[i][j] == 0) printf("  ");
		}
		printf("\n");
	}
	printf("\n");
}
