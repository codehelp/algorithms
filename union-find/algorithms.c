/*
 * algorithms.c
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
#include <math.h>
#include "union-find.h"


int main(int argc, char **argv)
{
	int p, q;
	int id[N];
/*
	setup_program_1(id);
	while(scanf("%d %d", &p, &q) == 2) {
		if (program_1_1(p, q, id) == 0) {
			return 0;
		}
	}
*/
/*
	setup_program_1(id);
	while(scanf("%d %d", &p, &q) == 2) {
		if (program_1_2(p, q, id) == 0) {
			return 0;
		}
	}
*/

	int sz[N];
	//double sum = 0.0;
	setup_program_1_3(id, sz);
	while(scanf("%d %d", &p, &q) == 2) {
		program_1_3(p, q, id, sz) == 0;
	}
	printf("%f\n", round(average(sz, N)));

/*
	int sz[N];
	setup_program_1_3(id, sz);
	while(scanf("%d %d", &p, &q) == 2) {
		program_1_4(p, q, id, sz) == 0;
	}
*/
	return 0;
}

