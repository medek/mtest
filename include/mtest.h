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
#ifndef MTEST_H_
#define MTEST_H_

#include <stdio.h>
#include <stdlib.h>

#define MTEST_SUITE_ENV(name) int tcount = 0;\
int ecount = 0;\
char *suite_name = #name ; \
printf("running suite \"%s\"\n", suite_name);

#define MTEST_PRINT_FINAL printf("%s: %d%% tests passed\n", suite_name, \
(int)(100*(float)((tcount - ecount) / (float)(tcount))));

#define RUN_TEST(name) if( name (&tcount, &ecount, #name ) < 0 ) {\
	printf("bailing from fatal error in test \"%s\"\n", #name );\
	exit(-1); }

#define DEFINE_TEST(n) static int n (int *tcount, int *ecount, char *name) \
{ int fail = 0; (*tcount)++;

#define END_TEST *ecount += fail ? 1 : 0; ;return fail; }

#define fail_unless(x) if( !( x )) \
{ \
	printf("%s:%d:%s: %s failed\n", __FILE__, __LINE__, name, #x);\
	fail++;\
}

#define fail_if(x) if ( x ) \
{ \
	printf("%s:%d:%s: %s failed\n", __FILE__, __LINE__, name, #x);\
	fail++;\
}

#define die_unless(x) if( !( x )) \
{ \
	printf("%s:%d:%s: %s epic failed\n", __FILE__, __LINE__, name, #x);\
	(*ecount)++;\
	return -1;\
}

#define die_if(x) if( x ) \
{ \
	printf("%s:%d:%s: %s epic failed\n", __FILE__, __LINE__, name, #x);\
	(*ecount)++;\
	return -1;\
}

#endif

