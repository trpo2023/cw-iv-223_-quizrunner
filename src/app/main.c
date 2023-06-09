#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib/extract.h"

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

    printf("\033[4;31m");
    printf("Сколько должно быть вопросов?\n");
    printf("\033[0m");
    while (scanf("%d", &n) != 1 || n > 16 || n < 1) {
        if (n < 1 && scanf("%d", &n) != 0) {
            printf("тест завершён, не успев начаться... \nВаш счёт: 0/0 "
                   "(100%%)\n");
            return 0;
        }

        printf("Ошибка! Введите корректное количество вопросов. \n");
        if (scanf("%d", &n) == 0)
            while (getchar() != '\n')
                ;
    }

    char* str1 = (char*)malloc(sizeof(char) * 200); // вариант ответа 1
    char* str2 = (char*)malloc(sizeof(char) * 200); // вариант ответа 2
    char* str3 = (char*)malloc(sizeof(char) * 200); // вариант ответа 3
    char* str4 = (char*)malloc(sizeof(char) * 200); // вариант ответа 4
    printf("\033[0;33m");
    printf("Тест начинается, ваше время пошло!\n");
    printf("\033[0m");
    double time_of_start = wtime();
    for (int i = 1; i <= n; i++) {
        printf("\n%s", get_question(i));
        int otvet = get_variants(i, str1, str2, str3, str4);
        printf("\033[0;35m");
        printf("1) %s\n2) %s\n3) %s\n4) %s\n", str1, str2, str3, str4);
        printf("\033[0m");
        while (scanf("%d", &answer) != 1 || answer < 1 || answer > 4) {
            if (getchar() == 'q') {
                printf("\033[0;35m");
                printf("Вы завершили тест.\n");
                printf("\033[0m");
                double percent = (double)score / n * 100;
                printf("\033[4;35m");
                printf("Ваш счет: %d из %d (%.2f%%)\n", score, n, percent);
                printf("\033[0m");
                FILE* fp;
                fp = fopen("result.txt", "a");
                if (fp == NULL) {
                    printf("Ошибка при открытии файла.\n");
                    return 1;
                }
                fprintf(fp, "Ваш счет: %d из %d (%.2f%%)\n", score, n, percent);
                fclose(fp);
                return 0;
            }
            printf("Ошибка! Введите номер ответа.\n");
            // while (getchar() != '\n')
            //     ;
        }

        if (answer == otvet) {
            printf("\033[1;32m");
            printf("Правильно!!\n");
            printf("\033[0m");
            score++;
        } else {
            printf("\033[1;31m");
            printf("Ошибочка :<\n");
            printf("\033[0m");
        }
    }
    double time_of_end = wtime();
    double percent = (double)score / n * 100;
    printf("Ваш счет: %d из %d (%.2f%%)\n", score, n, percent);
    printf("\033[5;36m");
    printf("Время выполнения: %.2f секунд!\n", time_of_end - time_of_start);
    printf("\033[0m");

    FILE* fp;
    fp = fopen("result.txt", "a");
    if (fp == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }
    fprintf(fp, "Ваш счет: %d из %d (%.2f%%)\n", score, n, percent);
    fclose(fp);
    free(str1);
    free(str2);
    free(str3);
    free(str4);
    return 0;
}
