#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

CTEST(extract, get_variants)
{
    char* str1 = (char*)malloc(sizeof(char) * 200);
    char* str2 = (char*)malloc(sizeof(char) * 200);
    char* str3 = (char*)malloc(sizeof(char) * 200);
    char* str4 = (char*)malloc(sizeof(char) * 200);
    get_variants(4, str1, str2, str3, str4);
    int number_of_placements = 0;
    printf("\n%s\n", str1);
    if (strcmp(str1, "6\n") == 0 || strcmp(str2, "6\n") == 0
        || strcmp(str3, "6\n") == 0 || strcmp(str4, "6\n") == 0)
        number_of_placements++;
    if (strcmp(str1, "1\n") == 0 || strcmp(str2, "1\n") == 0
        || strcmp(str3, "1\n") == 0 || strcmp(str4, "1\n") == 0)
        number_of_placements++;
    if (strcmp(str1, "3\n") == 0 || strcmp(str2, "3\n") == 0
        || strcmp(str3, "3\n") == 0 || strcmp(str4, "3\n") == 0)
        number_of_placements++;
    if (strcmp(str1, "8\n") == 0 || strcmp(str2, "8\n") == 0
        || strcmp(str3, "8\n") == 0 || strcmp(str4, "8\n") == 0)
        number_of_placements++;
    ASSERT_EQUAL(4, number_of_placements);
    free(str1);
    free(str2);
    free(str3);
    free(str4);
}

CTEST(extract, get_answer_place)
{
    int rand[] = {3, 4, 1, 2};
    int exp_place_of_answer = 1;
    int test_place_of_answer = get_answer_place(rand, 1);
    ASSERT_EQUAL(exp_place_of_answer, test_place_of_answer);
}

CTEST(extract, preparation)
{
    char string[] = {'s', 't', 'r', 'i', 'n', 'g', '\n'};
    preparation(string, 1);
    printf("%s", string);
    ASSERT_STR("ring\n", string);
}