/*
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2013 Gavin Massey <mdk@mystacktrace.org>

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.
*/
#include "mtest.h"
#include <string.h>

EXTERN_SUITE(external_suite);

DEFINE_TEST(string_len)
{
	fail_unless(strlen("hello") == 5);
	fail_unless(strlen("th\0is") == 2);
}
END_TEST

DEFINE_TEST(random_all_clear)
{
	fail_unless(NULL == 0);
	fail_unless(*"Hello" == 'H');
}
END_TEST

DEFINE_TEST(sizeof_test)
{
	fail_unless(sizeof(short) == 2);
	fail_unless(sizeof(int) == 4);
	fail_unless(sizeof(double) == 8);
	fail_unless(2 == 3);
}
END_TEST

START_SUITE(stuff)
	START_TCASE(stuff)
		string_len
	END_TCASE
	START_TCASE(other_stuff)
		random_all_clear,
		sizeof_test
	END_TCASE
END_SUITE

int main(int argc, char *argv[])
{
	MTEST_ENVIRONMENT
	RUN_SUITE(stuff)
	RUN_SUITE(external_suite);
	MTEST_PRINT_FINAL;
	return MTEST_FAIL_COUNT;
}

