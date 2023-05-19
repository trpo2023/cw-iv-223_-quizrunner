#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "extract.h"

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    int score = 0; // счёт
    int answer;    // ответ
    int n;         // кол-во вопросов

    printf("Сколько должно быть вопросов?\n");
    while (scanf("%d", &n) != 1 || n > 9 || n < 1)
    {
        if (n < 1)
        {
            printf("тест завершён, не успев начаться... \nВаш счёт: 0/0 (100%%)\n");
            return 0;
        }

        {
            printf("Ошибка! Введите корректное количество вопросов. \n");
            while (getchar() != '\n')
                ;
        }
    }

    char *str1 = (char *)malloc(sizeof(char) * 200); // вариант ответа 1
    char *str2 = (char *)malloc(sizeof(char) * 200); // вариант ответа 2
    char *str3 = (char *)malloc(sizeof(char) * 200); // вариант ответа 3
    char *str4 = (char *)malloc(sizeof(char) * 200); // вариант ответа 4

    printf("Тест начинается, ваше время пошло!\n");
    double time_of_start = wtime();
    for (int i = 1; i <= n; i++)
    {
        printf("\n%s", get_question(i));
        int otvet = get_variants(i, str1, str2, str3, str4);
        printf("1) %s\n2) %s\n3) %s\n4) %s\n", str1, str2, str3, str4);

        while (scanf("%d", &answer) != 1 || answer < 1 || answer > 4)
        {
            printf("Ошибка! Введите номер ответа.\n");
            while (getchar() != '\n')
                ;
        }

        if (answer == otvet)
        {
            printf("Правильно!!\n");
            score++;
        }
        else
        {
            printf("Ошибочка :<\n");
        }
    }
    double time_of_end = wtime();
    double percent = (double)score / n * 100;
    printf("Ваш счет: %d из %d (%.2f%%)\n", score, n, percent);
    printf("Время выполнения: %.2f секунд!\n", time_of_end - time_of_start);
    free(str1);
    free(str2);
    free(str3);
    free(str4);
    return 0;
}