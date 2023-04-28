#include <stdio.h>
#include <stdlib.h>

#include "extract.h"

int main()
{
    int score = 0; // счёт
    int answer;    // ответ
    int n;         // кол-во вопросов

    char *str1 = (char *)malloc(sizeof(char) * 200); // вариант ответа 1
    char *str2 = (char *)malloc(sizeof(char) * 200); // вариант ответа 2
    char *str3 = (char *)malloc(sizeof(char) * 200); // вариант ответа 3
    char *str4 = (char *)malloc(sizeof(char) * 200); // вариант ответа 4

    printf("Сколько должно быть вопросов?\n");
    scanf("%d", &n);
    printf("Генерация %d вопросов...\n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%s", get_question(i));
        get_variants(i, str1, str2, str3, str4);
        printf("%s%s%s%s", str1, str2, str3, str4);
        scanf("%d", &answer);
        if (answer == get_answer(i))
        {
            printf("Правильно!!\n");
            score++;
        }
        else
        {
            printf("Ошибочка :<\n");
        }
    }
    printf("Ваш счет: %d\n", score);

    return 0;
}