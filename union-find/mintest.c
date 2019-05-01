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

static char * test_end_state() {
	int i, id[N];
	for (i=0; i < N; i++) id[i] = 1;
	mu_assert("error, end state is invalid for uniform array", check(id, N) == 0);
	for (i=0; i < N; i++) id[i] = i;
	mu_assert("error, end state is invalid for unique array", check(id, N) == 1);
	return 0;
}

static char * test_connectivity_1() {
	int i, id[N], ret;
	for (i=0; i < N; i++) id[i] = i;
	setup_program_1(id);
	ret = program_1_1(3, 4, id);
	mu_assert("error, failed to detect new connection 3 4", ret == 1);
	ret = program_1_1(4, 9, id);
	mu_assert("error, failed to detect new connection 4 9", ret == 1);
	ret = program_1_1(8, 0, id);
	mu_assert("error, failed to detect new connection 8 0", ret == 1);
	ret = program_1_1(2, 3, id);
	mu_assert("error, failed to detect new connection 2 3", ret == 1);
	ret = program_1_1(5, 6, id);
	mu_assert("error, failed to detect new connection 5 6", ret == 1);
	ret = program_1_1(2, 9, id);
	mu_assert("error, failed to detect existing connection 2 9", ret == 2);
	ret = program_1_1(5, 9, id);
	mu_assert("error, failed to detect new connection 5 9", ret == 1);
	ret = program_1_1(7, 3, id);
	mu_assert("error, failed to detect new connection 7 3", ret == 1);
	ret = program_1_1(4, 8, id);
	mu_assert("error, failed to detect new connection 4 8", ret == 1);
	ret = program_1_1(5, 6, id);
	mu_assert("error, failed to detect existing connection 5 6", ret == 2);
	ret = program_1_1(0, 2, id);
	mu_assert("error, failed to detect existing connection 0 2", ret == 2);
	ret = program_1_1(6, 1, id);
	mu_assert("error, failed to completed connection 6 1", ret == 0);
	return 0;
}

static char * test_connectivity_2() {
	/*
	 * Note: the tree representation differs from _1
	 */
	int i, id[N], ret;
	for (i=0; i < N; i++) id[i] = i;
	setup_program_1(id);
	ret = program_1_2(3, 4, id);
	mu_assert("error, failed to detect new connection 3 4", ret == 1);
	ret = program_1_2(4, 9, id);
	mu_assert("error, failed to detect new connection 4 9", ret == 1);
	ret = program_1_2(8, 0, id);
	mu_assert("error, failed to detect new connection 8 0", ret == 1);
	ret = program_1_2(2, 3, id);
	mu_assert("error, failed to detect new connection 2 3", ret == 1);
	ret = program_1_2(5, 6, id);
	mu_assert("error, failed to detect new connection 5 6", ret == 1);
	ret = program_1_2(2, 9, id);
	mu_assert("error, failed to detect existing connection 2 9", ret == 2);
	ret = program_1_2(5, 9, id);
	mu_assert("error, failed to detect new connection 5 9", ret == 1);
	ret = program_1_2(7, 3, id);
	mu_assert("error, failed to detect new connection 7 3", ret == 1);
	ret = program_1_2(4, 8, id);
	mu_assert("error, failed to detect new connection 4 8", ret == 1);
	ret = program_1_2(5, 6, id);
	mu_assert("error, failed to detect existing connection 5 6", ret == 2);
	ret = program_1_2(0, 2, id);
	mu_assert("error, failed to detect existing connection 0 2", ret == 2);
	ret = program_1_2(6, 1, id);
	mu_assert("error, failed to detect new connection 6 1", ret == 1);
	ret = program_1_2(5, 8, id);
	mu_assert("error, failed to detect existing connection 5 8", ret == 2);
	printf("Complete\n\n");
	return 0;
}

static char * test_connectivity_3() {
	/*
	 * Note: the tree representation differs from _1
	 */
	int i, id[N], sz[N], ret;
	for (i=0; i < N; i++) id[i] = i;
	setup_program_1_3(id, sz);
	ret = program_1_3(3, 4, id, sz);
}

static char * all_tests() {
	mu_run_test(test_end_state);
	mu_run_test(test_connectivity_1);
	mu_run_test(test_connectivity_2);
	mu_run_test(test_connectivity_3);
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
