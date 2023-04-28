#include <stdio.h>

int main()
{
    int score = 0; // счёт
    int answer;    // ответ
    int n;         // кол-во вопросов
    printf("Сколько должно быть вопросов?\n");
    scanf("%d", &n);
    printf("Генерация %d вопросов...\n", n);
    while (n != 0)
    {
        printf("Вопрос 1: Сколько будет 2 + 2?\n");
        printf("1) 4\n2) 5\n3) 6\n");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            printf("Правильно!\n");
            score++;
            break;
        default:
            printf("Неправильно...:(\n");
            break;
        }
        n--;
    }
    printf("Ваш счет: %d\n", score);

    return 0;
}