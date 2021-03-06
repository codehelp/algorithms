/*
 * graph.c
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
#include "vertices.h"

int main(int argc, char **argv)
{
	/*
	 * matrix uses the space of V^2
	 * use for dense graphs
	 * constant time to find an edge between i and j
	 */
	int i, j, adj_matrix[V][V];
	setup_matrix(adj_matrix);

	while (scanf("%d %d", &i, &j) == 2) {
		add_edge(i, j, adj_matrix);
	}
	output_matrix(adj_matrix);
	/* alternative using linked lists
	 * Uses space of V + E (number of pairs of integers)
	 * better for sparse graphs.
	 * faster processing for all edges in the graph
	*/
	/*
	int adj_list[V];
	for (i = 0; i < V; i++) adj_list[i] = NULL;
	while (scanf("%d %d", &i, &j) == 2) {
		adj_list[j] = allocNode(i, adj[j]);
		adj_list[i] = allocNode(i, adj[i]);
	}
	*/
	return 0;
}
