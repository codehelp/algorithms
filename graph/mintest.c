/*
 * mintest.c
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
#include "mintest.h"
#include "vertices.h"

int tests_run = 0;

static char * test_end_state() {
	int i, j, adj_matrix[V][V];
	setup_matrix(adj_matrix);
	add_edge(0, 2, adj_matrix);
	mu_assert("error, end state is invalid for 0 2", adj_matrix[0][2] == 1);
	mu_assert("error, end state is invalid for 0 2", adj_matrix[2][0] == 1);
	mu_assert("error, end state is invalid for 0 2", adj_matrix[0][0] == 1);
	mu_assert("error, end state is invalid for 0 2", adj_matrix[2][2] == 1);
	add_edge(1, 4, adj_matrix);
	add_edge(2, 5, adj_matrix);
	add_edge(3, 6, adj_matrix);
	add_edge(0, 4, adj_matrix);
	add_edge(6, 0, adj_matrix);
	add_edge(1, 3, adj_matrix);
	mu_assert("error - invalid edge at 1 5",  adj_matrix[1][5] == 0);
	mu_assert("error - invalid edge at 2 4",  adj_matrix[2][4] == 0);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_end_state);
	return 0;
}

int main(int argc, char **argv) {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
