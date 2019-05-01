/*
 * heads.c
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

/*
 * Coin flipping simulation
 */


#include <stdio.h>
#include <stdlib.h>

int heads(void) {
	return rand() < RAND_MAX/2;
}

int main(int argc, char **argv)
{
	int i, j, cnt;
	int N = atoi(argv[1]), M = atoi(argv[2]);
	int *f = malloc((N+1)*sizeof(int));
	for (j=0; j <= N; j++) f[j] = 0;
	for (i=0; i < M; i++, f[cnt]++)
		for (cnt = 0, j = 0; j <= N; j++)
			if (heads()) cnt++;
	for (j = 0; j <= N; j++) {
		printf("%2d ", j);
		for (i=0; i < f[j]; i+=10) printf("*");
		printf("\n");
	}
	return 0;
}

