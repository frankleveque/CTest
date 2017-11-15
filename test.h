#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <assert.h>

extern int tests;
extern int checks;
extern int passed;
extern int failed;
extern const double delta;

#define FILENAME_AUX (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define CHECK_NULL(a) \
    if(true) {	       \
    asserts++;         \
    if(!a){            \
	passed++;      \
    }else{             \
	failed++;      \
	printf("%s:%-5d    0x%p not null\n", FILENAME_AUX,__LINE__, (void*)a);	\
    }                                                       \
    fflush(0);                                              \
}

#define CHECK_TRUE(a)                      \
if(true){                                   \
    bool resA = a;                          \
    asserts++;                              \
    if(resA == true){                       \
        passed++;                           \
    }else{                                  \
        failed++;                           \
        printf("%s:%-5d    %s == %s\n",     \
               FILENAME_AUX, __LINE__,      \
               (resA?"true":"false"),       \
                "true");                    \
    }                                       \
    fflush(0);                              \
}

#define CHECK_FALSE(a)                     \
if(true){                                   \
    bool resA = a;                          \
    asserts++;                              \
    if(resA == false){                      \
        passed++;                           \
    }else{                                  \
        failed++;                           \
        printf("%s:%-5d    %s == %s\n",     \
               FILENAME_AUX, __LINE__,      \
               (resA?"true":"false"),       \
                "false");                   \
    }                                       \
    fflush(0);                              \
}


#define CHECK_EQ_BOOL(a, b)			\
if(true){					\
    bool resA = a;				\
    bool resB = b;				\
    asserts++;					\
    if(resA == resB){				\
	passed++;                               \
    }else{					\
	failed++;				\
	printf("%s:%-5d    %s == %s\n",		\
	       FILENAME_AUX, __LINE__,		\
	       (resA?"true":"false"),		\
	       (resB?"true":"false"));		\
    }						\
    fflush(0);					\
}

#define CHECK_EQ_DBL(a, b) \
if(true){                   \
    double resA = a;        \
    double resB = b;        \
    asserts++;              \
    if(fabs(resA - resB) <= delta){		\
	passed++;           \
    }else{                  \
	failed++;           \
	printf("%s:%-5d    %f == %f\n",FILENAME_AUX,__LINE__,resA,resB);  \
    }                       \
    fflush(0);              \
}    

#define CHECK_EQ_STR(a, b)         \
    if(true) {                      \
    const char* resA = a;           \
    const char* resB = b;           \
    asserts++;                      \
    if(strcmp(resA, resB) == 0){    \
	passed++;                   \
    }else{                          \
	failed++;                   \
	printf("%s:%-5d    %s == %s\n",FILENAME_AUX,__LINE__,resA,resB);	\
    }                               \
    fflush(0);                      \
}

#define CHECK_EQ_INT(a, b)                           \
    if(true){	                                      \
    int resA = a;                                     \
    int resB = b;                                     \
    asserts++;                                        \
    if (resA != resB){                                \
        failed++;		                                  \
        printf("%s:%-5d    %i == %i\n",FILENAME_AUX,__LINE__,resA,resB);  \
    }else{                                                \
        passed++;                                         \
    }                                                     \
    fflush(0);                                            \
}

#define RUN_TEST(test) if(true) { test(); tests++; }
#define TEST_HEADER if(true) { printf("---- %s \n",__func__); }

#define TEST_RESULTS \
if(true){								\
    assert(passed + failed == asserts);					\
    printf("-------------------------------------------------------------------------------\n");  \
    printf("%-15s%-7i\n%-15s%-7i\n%-15s%-7i\n%-15s%-7i\n",                                            \
	   "Tests Run:", tests,                                                                       \
	   "Total Checks:", asserts,                                                                 \
	   "Passed:", passed,                                                                         \
       	   "Failed:", failed);                                                                    \
    printf(failed > 0 ? "FAILED\n" : "All tests passed\n");                                       \
    fflush(0);                                                                                    \
}

