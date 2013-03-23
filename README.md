#mtest
Lightweight(it's one header file) testing framework. Very basic, only does
the bare necessities since that's all I use. The fail\_unless/if stuff
comes from libcheck's naming convention as I wrote this to replace it so
I can run my tests on windows.

#Example
Here's an example of using it:
```
#include "mtest.h"

DEFINE_TEST(external_test)
{
	fail_if(NULL);
}
END_TEST

DEFINE_TEST(will_pass)
{
	fail_unless(1==1);
}
END_TEST

void external_suite()
{
	MTEST_SUITE_ENV(external);
	RUN_TEST(external_test);
	RUN_TEST(will_pass);
	MTEST_PRINT_FINAL;
}

```

