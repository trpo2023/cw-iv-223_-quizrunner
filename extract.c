#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "extract.h"

void randomize(int *arr)
{
    int i = 0;
    srand(time(NULL));
    while (i < 4)
    {
        int tmp = rand() % 4;
        if (arr[tmp] == 0)
        {
            arr[tmp] = i + 1;
            i++;
        }
    }
}

void preparation(char *str, int j)
{
    for (int k = 0; k < j; k++)
    {
        int i = 0;
        while (str[i + 1] != '\0')
        {
            str[i] = str[i + 2];
            i++;
        }
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
    preparation(words, 1);
    return words;
}

int get_variants(int number_of_question, char *str, char *str1, char *str2, char *str3)
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
    int *rand = (int *)calloc(sizeof(int), 4);
    randomize(rand);
    fgets(words, 200, file); // нужен для пропуска строки. Потенциально получение вопроса в этой функции, а не в отдельной
    int answer = 0;
    for (i = 0; i < 4; i++)
    {
        switch (rand[i])
        {
        case 1:
            fgets(str, 200, file);
            if (get_answer(number_of_question) == (i + 1))
                answer = rand[i];
            break;
        case 2:
            fgets(str1, 200, file);
            if (get_answer(number_of_question) == (i + 1))
                answer = rand[i];
            break;
        case 3:
            fgets(str2, 200, file);
            if (get_answer(number_of_question) == (i + 1))
                answer = rand[i];
            break;
        case 4:
            fgets(str3, 200, file);
            if (get_answer(number_of_question) == (i + 1))
                answer = rand[i];
            break;
        }
    }
    fclose(file);
    free(words);
    free(rand);
    preparation(str, 2);
    preparation(str1, 2);
    preparation(str2, 2);
    preparation(str3, 2);
    return answer;
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
        {
            if (i == number_of_question)
                break;
            i++;
        }
    }
    fclose(file);
    preparation(words, 1);
    return atoi(words);
}