#mtest
Lightweight(it's one header file) testing framework. Very basic, only does
the bare necessities since that's all I use. The fail\_unless/if stuff
comes from libcheck's naming convention as I wrote this to replace it so
I can run my tests on windows.

#Example
Here's an example of using it:
```
#include "mtest.h"
#include <string.h>

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
	fail_if(sizeof(int) != 4);
	/*
	 	die_if/unless will cause early exit. Any tests
		after it will not be run
	*/
	die_unless(sizeof(double) == 8);
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
	MTEST_PRINT_FINAL;
	return MTEST_FAIL_COUNT;
}
```

