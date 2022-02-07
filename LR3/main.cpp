#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <cmath>



//Лабораторная работа 3, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)

//функция - возвести целое число в степень
float Power(float value, unsigned short p)
{
    unsigned short i;
    float result  = 1;
    for (i = 0; i < p; i++)
        result*= value;

    return result;
}


//фукнция - вычислить значение i-того элемента ряда
float getAiValue(int i)
{
    float a_i;
    float uno;
    if (i % 2 == 0)
        uno = 1.0;
    else
        uno = -1.0;

    a_i = uno * ((i + 1) / (5.0 * i + Power(3.0, (i + 1))));

    return a_i;
}

//фукнция - изменить количество пробелов для печати. зависит от типа печатаемой функции (окружность или прямая)
void changeH(short& h, float y, short mashtab, bool is_line = false)
{
    if (is_line)
        h = y  * mashtab + 0.5;
    else
        h = (y - 1)  * mashtab + 0.5;
}

int main() {
    system("chcp 65001");
    char key;


    //Задание 1
    do
    {
        float epcilon = 0;
        int count = 0;
        float a_i = getAiValue(0);
        float count_sum = 0;
        float sum = 0;

        printf("\n\nЗадание 1\nВведите значение точности: ");
        scanf("%f", &epcilon);
        printf("Введите значение count: ");
        scanf("%d", &count);

        if (count == 0)
            count_sum = a_i;
        else if (fabsf(getAiValue(count)) < epcilon)
        {
            printf("Сумма первых %d членов не будет вычислена, т. к. %d-й элемент не удовлетворяет выбранной точности.\n", count, count);
        }

        int i = 1;
        printf("|------------------------|\n");
        printf("|  i |        a_i        |\n");
        printf("|----|-------------------|\n");

        while (fabsf(a_i) > epcilon)
        {

            printf("| %2d | %17.10f |\n", i, a_i);
            a_i = getAiValue(i);
            sum += a_i;
            if (i == count)
                count_sum = sum;

            i++;
        }
        printf("|------------------------|\n");
        printf("Сумма элементов для выбранной точности = %f\nКоличество итераций = %d\n", sum, i - 1);
        if (count_sum)
            printf("Сумма первых %d членов = %10.10f\n", count, count_sum);

        printf("Продолжить работу? (y/n)");
        key = _getch();
    } while (key == 'y');


    //Задание 2

    printf("\n\nЗадание 2");
    printf("\n|   X   |      Y     |\n");
    printf("|-------|------------|\n");
    float x, y;
    const unsigned short int mashtab = 10;
    short h;
    for (short n = 0; n < 5; n++)
    {

        for (x = 0; x < 4; x += 0.25)
        {
            if(x < 2)
            {
                y = 1 + sqrt(1 - Power((x - 1), 2));
                changeH(h, y, mashtab);
            }
            else if(x < 3)
            {
                y = 1 + sqrt(1 - Power((x - 3), 2));
                changeH(h, y, mashtab);
            }
            else
            {
                y = 4 - x;
                h = y  * mashtab + 0.5;
                changeH(h, y, mashtab, true);
            }

            printf("| %5.2lf | %10.7lf | ", (x + n * 4), y);

            for (; h > 0; h--)
                printf(" ");
            printf("*\n");

        }
    }
    printf("|-------|------------|\n");

    printf("Press any key...");
    _getch();
    return 0;
}
