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

START_SUITE(external_suite)
	START_TCASE(boo)
		external_test,
		will_pass
	END_TCASE
END_SUITE

