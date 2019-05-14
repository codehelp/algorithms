/*
 * depth.c
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
#include "item.h"
#include "queue.h"

#define V 10
Item visited [3];
Qlink adjacent[3];


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

void traverseBreadth(Item k, void(*visit)(int)) {
	/* visit all nodes connected to node k in a graph
	 * put k into a FIFO queue, loop over the next node.
	 * If that has not been visited, visit and push all
	 * the unvisited nodes on the adjacency list of the
	 * query node onto the queue. Continue until the queue
	 * is empty.
	 * May leave multiple copies of each node on the stack.
	 * May need to use a forget-the-old-item stack policy.
	 * 
	 * Lots of search operations, fanning out to cover the graph.
	 *  */

	Qlink t;
	QueueInit();
	QueuePut(k);
	while (!QueueEmpty()) {
		if (visited[k = QueueGet()] == 0) {
			(*visit)(k);
			visited[k] = 1;
			for (t = adjacent[k]; t != NULL; t = t->next) {
				if (visited[t->item] == 0) {
					QueuePut(t->item);
				}
			}
		}
	}
}

void traverseDepth(Item k, void (*visit)(int)) {
	/* Single search operation probing until a dead end is
	 * found, then retracing to find an open path. */
	Qlink t;
	(*visit)(k);
	/* guard against revisiting nodes
	 * - cannot happen in a tree. */
	visited[k] = 1;
	/* building the adjacency list is proportional to V + E */
	for (t = adjacent[k]; t != NULL; t = t->next) {
		if (!visited[t->item]) traverseDepth(t->item, visit);
	}
}
