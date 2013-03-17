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

typedef int (*mtest_test)(int *tcount, int *ecount);

typedef struct mtest_tcase_s
{
	/** name of test case */
	const char *name;
	/** null terminated array of tests */
	const mtest_test *tests;
} mtest_tcase;

typedef struct mtest_suite_s
{
	/** suite name */
	const char *name;
	/** null terminated array of test cases */
	const mtest_tcase *test_cases;
} mtest_suite;

#define DEFINE_TEST(name) static int name (int *tcount, int *ecount) \
{ int fail = 0; (*tcount)++;

#define END_TEST *ecount += fail ? 1 : 0; ;return fail; }

#define START_SUITE(name) \
const mtest_suite mtest_##name = { #name , (const mtest_tcase[]) {

#define START_TCASE(name) \
{ #name , (const mtest_test[]) {

#define END_TCASE \
,(mtest_test)NULL}},

#define END_SUITE \
 { NULL, NULL}}};

#define MTEST_ENVIRONMENT \
int mtest_glob_err = 0;\
int mtest_glob_pass = 0;\
int mtest_status = 0; \
int mtest_error_count = 0;\
int mtest_test_count = 0; \
int mtest_tcase_count = 0; \
int mtest_terr_count = 0; \
const mtest_test *__test = NULL;\
const mtest_tcase *__tcase = NULL;

#define EXTERN_SUITE(name) extern const mtest_suite mtest_##name ;

#define MTEST_FAIL_COUNT mtest_glob_err

#define MTEST_PRINT_FINAL printf("%d%% tests passed\n",(int)(100*(float)(\
mtest_glob_pass / (float)(mtest_glob_pass + mtest_glob_err))));

#define RUN_SUITE(suite_name) \
	mtest_status = 0;\
	mtest_error_count = 0;\
	mtest_test_count = 0;\
	mtest_tcase_count = 0;\
	mtest_terr_count = 0;\
	__tcase = mtest_##suite_name .test_cases;\
	printf("running test suite: %s\n", mtest_##suite_name .name); \
	while(__tcase->name && __tcase->tests) \
	{ \
		mtest_tcase_count++;\
		__test = __tcase->tests;\
		while(*__test) \
		{ \
			mtest_status = (*__test)(&mtest_test_count,\
					&mtest_error_count); \
			if(mtest_status < 0) \
				goto suite_name##_mtest_exit;\
			__test++;\
		} \
		printf("\ttest case: %s\t",\
			 __tcase->name);\
		fflush(stdout);\
		if(mtest_error_count > 0)\
		{\
			mtest_terr_count++;\
			printf("failed (%d)\n", mtest_error_count);\
		}\
		else\
			printf("passed (%d)\n", mtest_test_count);\
		mtest_glob_err += mtest_error_count;\
		mtest_glob_pass += mtest_test_count - mtest_error_count;\
		mtest_test_count = mtest_error_count = 0;\
		__tcase++;\
	}\
suite_name##_mtest_exit:\
	if(mtest_error_count > 0)\
		mtest_terr_count++;\
	printf("\ttest cases: %d passed, %d failed\n",\
		mtest_tcase_count - mtest_terr_count,\
		mtest_terr_count);\
	if(mtest_status < 0)\
	{\
		printf("Tests stopped early on epic failure\n"); \
		exit(-1);\
	}

#define fail_unless(x) if( !( x )) \
{ \
	printf("%s:%d: %s failed\n", __FILE__, __LINE__, #x);\
	fail++;\
}

#define fail_if(x) if ( x ) \
{ \
	printf("%s:%d: %s failed\n", __FILE__, __LINE__, #x);\
	fail++;\
}

#define die_unless(x) if( !( x )) \
{ \
	printf("%s:%d: %s epic failed\n", __FILE__, __LINE__, #x);\
	(*ecount)++;\
	return -1;\
}

#define die_if(x) if( x ) \
{ \
	printf("%s:%d: %s epic failed\n", __FILE__, __LINE__, #x);\
	(*ecount)++;\
	return -1;\
}

#endif

