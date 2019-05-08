/*
 * mintest.c
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


#include <string.h>
#include <stdio.h>
#include "mintest.h"
#include "array-llist.h"

int tests_run = 0;

static char * test_conversions() {
	const char * str_base = "0123456789";
	for (int i = 0; i < strlen(str_base); i++) {
		mu_assert(
			"error, str_base charToInt conversion failed", 
			(2 * charToInt(str_base[i]) == (2 * i)));
	}
	/* base needs to be null terminated for strlen */
	const char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
	for (int i = 0; i < strlen(base); i++) {
		mu_assert(
			"error, base charToInt conversion failed", 
			(2 * charToInt(base[i]) == (2 * i)));
	}
	return 0;
}

static char * test_stack() {
	stackInit();
	mu_assert("error, stack not empty", stackEmpty());
	stackPush(0);
	mu_assert("error, stack is empty", stackEmpty() == 0);
	mu_assert("error, stack does not contain first item", stackPop() == 0);
	stackPush(1);
	mu_assert("error, stack is empty", stackEmpty() == 0);
	mu_assert("error, stack does not contain correct item", stackPop() == 1);
	mu_assert("error, stack not empty", stackEmpty());
	stackPush(2);
	mu_assert("error, stack is empty", stackEmpty() == 0);
	stackPush(3);
	mu_assert("error, stack is empty", stackEmpty() == 0);
	mu_assert("error, stack does not contain most recent item", stackPop() == 3);
	mu_assert("error, stack does not contain earlier item", stackPop() == 2);
	mu_assert("error, stack not empty", stackEmpty());
	return 0;
}

static char * all_tests() {
	mu_run_test(test_conversions);
	mu_run_test(test_stack);
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
