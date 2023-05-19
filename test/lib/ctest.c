#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/extract.h"

CTEST(extract, get_question)
{
    char* exp = get_question(5);
    char test[] = {"Химическая формула воды?\n"};
    printf("%s1\n%s", exp, test);
    ASSERT_STR(exp, test);
}

CTEST(extract, get_answer)
{
    int exp = get_answer(10);
    int test = 1;
    ASSERT_EQUAL(test, exp);
}
