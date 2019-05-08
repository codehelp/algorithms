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

static char * test_end_state() {
	int N = 10;
	int i, id[N];
	for (i=0; i < N; i++) id[i] = 1;
	mu_assert("error, end state is invalid for uniform array", check(id, N) == 0);
	for (i=0; i < N; i++) id[i] = i;
	mu_assert("error, end state is invalid for unique array", check(id, N) == 1);
	return 0;
}


static char * test_connectivity() {
	UFinit(10);
	int ret;

	ret = UFunion(3, 4);
	mu_assert("error, failed to insert new connection 3 4", ret == 0);
	mu_assert("error, failed to detect new connection 3 4", UFfind(3, 4) == 1);

	ret = UFunion(4, 9);
	mu_assert("error, failed to insert new connection 4 9", ret == 0);
	mu_assert("error, failed to detect new connection 4 9", UFfind(4, 9) == 1);

	ret = UFunion(8, 0);
	mu_assert("error, failed to insert new connection 8 0", ret == 0);
	mu_assert("error, failed to detect new connection 8 0", UFfind(8, 0) == 1);

	ret = UFunion(2, 3);
	mu_assert("error, failed to insert new connection 2 3", ret == 0);
	mu_assert("error, failed to detect new connection 2 3", UFfind(2, 3) == 1);

	ret = UFunion(5, 6);
	mu_assert("error, failed to insert new connection 5 6", ret == 0);
	mu_assert("error, failed to detect new connection 5 6", UFfind(5, 6) == 1);

	ret = UFunion(2, 9);
	mu_assert("error, failed to detect existing connection 2 9", ret == 2);
	mu_assert("error, failed to find existing connection 2 9", UFfind(2, 9) == 1);

	ret = UFunion(5, 9);
	mu_assert("error, failed to insert new connection 5 9", ret == 0);
	mu_assert("error, failed to detect new connection 5 9", UFfind(5, 9) == 1);

	ret = UFunion(7, 3);
	mu_assert("error, failed to insert new connection 7 3", ret == 0);
	mu_assert("error, failed to detect new connection 7 3", UFfind(7, 3) == 1);

	ret = UFunion(4, 8);
	mu_assert("error, failed to insert new connection 4 8", ret == 0);
	mu_assert("error, failed to detect new connection 4 8", UFfind(4, 8) == 1);

	ret = UFunion(5, 6);
	mu_assert("error, failed to detect existing connection 5 6", ret == 2);
	mu_assert("error, failed to find existing connection 5 6", UFfind(5, 6) == 1);

	ret = UFunion(0, 2);
	mu_assert("error, failed to detect existing connection 0 2", ret == 2);
	mu_assert("error, failed to find existing connection 0 2", UFfind(0, 2) == 1);

	ret = UFunion(6, 1);
	mu_assert("error, failed to insert new connection 6 1", ret == 0);
	mu_assert("error, failed to detect new connection 6 1", UFfind(6, 1) == 1);

	return 0;
}

static char * all_tests() {
	mu_run_test(test_end_state);
	mu_run_test(test_connectivity);
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
