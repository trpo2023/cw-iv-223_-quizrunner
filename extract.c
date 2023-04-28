#include <stdio.h>
#include <stdlib.h>

#include "extract.h"

void preparation(char *str)
{
    int i = 0;
    while (str[i + 1] != '\0')
    {
        str[i] = str[i + 2];
        i++;
    }
}

char *get_question(int number_of_question)
{
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL)
    {
        printf("\nНе удаётся открыть файл!");
        return "\n";
    }

    char *words = (char *)malloc(sizeof(char) * 200);
    int i = 1;
    while (i <= number_of_question)
    {
        fgets(words, 200, file);
        if (words[0] == '*')
            i++;
    }
    fclose(file);
    preparation(words);
    return words;
}

void get_variants(int number_of_question, char *str, char *str1, char *str2, char *str3)
{
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL)
    {
        printf("\nНе удаётся открыть файл!");
    }

    char *words = (char *)malloc(sizeof(char) * 200);
    int i = 1;
    while (i <= number_of_question)
    {
        fgets(words, 200, file);
        if (words[0] == '-')
            i++;
    }
    fgets(words, 200, file); // нужен для пропуска строки. Потенциально получение вопроса в этой функции, а не в отдельной
    fgets(str, 200, file);
    fgets(str1, 200, file);
    fgets(str2, 200, file);
    fgets(str3, 200, file);
    fclose(file);
    free(words);
    preparation(str);
    preparation(str1);
    preparation(str2);
    preparation(str3);
}

int get_answer(int number_of_question)
{
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL)
    {
        printf("\nНе удаётся открыть файл!");
        return 0;
    }

    char *words = (char *)malloc(sizeof(char) * 200);
    int i = 1;
    while (i <= number_of_question)
    {
        fgets(words, 200, file);
        if (words[0] == '1')
            i++;
    }
    fclose(file);
    preparation(words);
    return atoi(words);
}