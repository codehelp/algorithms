/*
 * geometric.c
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

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

plink **grid;
int G;
float d;
int count = 0;

float randFloat() {
	return 1.0*rand()/RAND_MAX;
}

float distance(point a, point b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	//distance is a hypotenuse
	return sqrt(dx * dx + dy * dy);
}

void gridinsert(float x, float y) {
	int i, j;
	plink s;
	int X = x * G + 1;
	int Y = y * G + 1;
	plink t = malloc(sizeof *t);
	t->p.x = x;
	t->p.y = y;
	for (i = X - 1; i <= X + 1; i++)
		for (j = Y - 1; j <= Y + 1; j++)
			for (s = grid[i][j]; s != NULL; s = s->next)
				if (distance(s->p, t->p) < d) count++;
	t->next = grid[X][Y];
	grid[X][Y] = t;
}

plink **malloc_2d(int r, int c) {
	int i;
	plink **t = malloc(r * sizeof(plink *));
	for (i = 0; i < r; i++)
		t[i] = malloc(c * sizeof(plink));
	return t;
}

int main(int argc, char **argv)
{
	/*
	 * Builds N randomly generated points in the unit square
	 * and checks the number of edges shorter than d.
	 * N must be an integer greater than 1
	 * d must be a floating point number between 0.00 and 1.00
	 * The square is divided into a grid which is a
	 * two dimensional array of linked lists. One list for each
	 * grid square. All points within distance d of any given
	 * point are either in the same grid square of an adjacent
	 * grid square.
	 */
	int i, j, N = atoi(argv[1]);
	d = atof(argv[2]);
	if (N <= 1) {
		printf("The number of random points must be "
			"an integer greater than 1\n");
		return 1;
	}
	if (d > 1.0) {
		printf("Line length must be a float and "
			"less than or equal to 1.00\n");
		return 2;
	}
	G = 1 / d;

	srand(time(0));  // ensure different numbers on each run

	// initialize an empty grid
	grid = malloc_2d(G + 2, G + 2);
	for (i = 0; i < G + 2; i++)
		for (j = 0; j < G + 2; j++)
			grid[i][j] = NULL;

	for (i = 0; i < N; i++)
		gridinsert(randFloat(), randFloat());
	printf("%d edges shorter than %f\n", count, d);
	return 0;
}

