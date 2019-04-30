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
#include "union-find.h"

int tests_run = 0;

int foo = 7;
int bar = 5;

static char * test_end_state() {
	int i, id[N];
	for (i=0; i < N; i++) id[i] = 1;
	mu_assert("error, end state is invalid", check(id, N) == 0);
	return 0;
}

static char * test_bar() {
	mu_assert("error, bar != 5", bar == 5);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_end_state);
	mu_run_test(test_bar);
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
