#include <stdio.h>
#include <cstdlib>
#include "Point.h"
#include <float.h>


//Лабораторная работа 8, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)

//чиста буфера scanf()
void cleanScanfBuffer()
{
    while ((getchar()) != '\n');
}

//поменять точки в массиве местами
void swapPointsInArray(Point &point_a, Point &point_b)
{
    Point point_c = point_a;
    point_a = point_b;
    point_b = point_c;
}

//заполнить массив по порядку от x1 с шагом k
void arrayFillStep(Point *array_points, short size, int value, short STEP)
{

    for (int i = 0; i < size; i++)
    {
        array_points[i].x = value;
        array_points[i].y = value;
        value += STEP;
    }
}

//заполнить массив случайными значениями
void arrayFillRandomValues(Point *array_points, short size)
{
    const unsigned short MIN = 0;
    const unsigned short MAX = 100; //макс. число, помещающееся в два байта
    for (int i = 0; i < size; i++)
    {
        array_points[i].x = MIN + rand()%(MAX - MIN + 1);
        array_points[i].y = MIN + rand()%(MAX - MIN + 1);
    }
}

//заполнить массив с клавиатуры
void arrayFillFromKeyboard(Point *array_points, short size)
{
    int x = 0; int y = 0;
    for (short i = 0; i < size; i++)
    {
        //нет проверок на корректность данных, т.к. за нас этим занимается компилятор
        //если ввести вещественное число, то запишется только целая часть от него, а если строку, то 0
        printf("\nВведите значение x: ");
        scanf("%d", &x);
        printf("\nВведите значение y: ");
        scanf("%d", &y);
        array_points[i].x = x;
        array_points[i].y = y;
    }
}

//вывод массива точек на экран
void printarray(Point *array_points, short size)
{
    printf("|------|-------|-------|------------|\n");
    printf("|  i   |  x    |  y    |  Distance  |\n");
    printf("|------|-------|-------|------------|\n");

    for (short i = 0; i < size; i++)
    {
        printf("| %4d | %5d | %5d | %10.3f |\n", i, array_points[i].x, array_points[i].y,
               findDistanceBetweenPointAndTheOriginOfCoordinates(array_points[i]));
    }
    printf("|------|-------|-------|------------|\n");
}

void printpoint(Point point)
{
    printf("|-------|-------|------------|\n");
    printf("|  x    |  y    |  Distance  |\n");
    printf("|-------|-------|------------|\n");
    printf("| %5d | %5d | %10.3f |\n", point.x, point.y,
           findDistanceBetweenPointAndTheOriginOfCoordinates(point));
    printf("|-------|-------|------------|\n");
}

//найти точку, находящуюся ближе всех к началу координат, и точку
//находящуюся дальше всех от начала координат, и поменять их местами
void findClosestAndFarestPointsAndChangeTheirPlaces(Point *array_points, short size)
{
    short min_i, max_i;
    float temp;
    float min = DBL_MAX;
    float max = DBL_MIN;

    for (short i = 0; i < size; i++)
    {
        temp = findDistanceBetweenPointAndTheOriginOfCoordinates(array_points[i]);
        if (temp > max_i)
        {
            max = temp;
            max_i = i;
        }
        else if (temp < min_i)

        {
            min = temp;
            min_i = i;
        }
    }
    swapPointsInArray(array_points[min_i], array_points[max_i]);
    printf("\nСледующие точки поменялись местами:\n");
    printpoint(array_points[min_i]);
    printf("\n");
    printpoint(array_points[max_i]);
}

//найти в массиве две точки, расстояние между которыми наибольшее
void findPointsWithMaxDistanceBetweenThem(Point *array_points, short size)
{
    float max_distance = DBL_MIN;
    float current_distance;
    Point pa, pb;
    for (short i = 0; i < size; i++)
    {
        for (short j = 0; j < size; j++)
        {
            if (j != i)
            {
                current_distance = findDistanceBetweenPointAndAnotherPoint(array_points[i], array_points[j]);
                if (current_distance > max_distance)
                {
                    max_distance = current_distance;
                    pa = array_points[i];
                    pb = array_points[j];
                }
            }
        }
    }
    //выведем найденные точки и расстояние между ними
    printf("\nНиже расположена информация о двух точках, расстояние между которыми наибольшее.\n");
    printpoint(pa);
    printpoint(pb);
    printf("Расстояние: %f", max_distance);

}

//переместить в начало массива точки, лежащие в окружности заданного радиуса расположенной в начале координат
void relocatePointsInSpecificRadiusToTheBeginningOfArray(Point *array_points, short size, float R)
{
    float temp, temp_2;
    Point temp_array[size];
    for (short i = 0; i < size; i++)
    {
        temp = findDistanceBetweenPointAndTheOriginOfCoordinates(array_points[i]);
        if (temp < R)
        {
            for (short j = 0; j < size; j++)
            {
                if (j < i)
                {
                    temp_2 = findDistanceBetweenPointAndTheOriginOfCoordinates(array_points[j]);
                    if (temp_2 >= R)
                        swapPointsInArray(array_points[i], array_points[j]);
                }

            }
        }
    }
}

//напечатать меню
void printmenu()
{
    printf("\n\nМеню:"
           "\n1 - напечатать массив"
           "\n2 - найти точку, находящуюся ближе всех к началу координат, и точку,\n"
           "    находящуюся дальше всех от начала координат, и поменять их местами."
           "\n3 - найти в массиве две точки, расстояние между которыми наибольшее."
           "\n4 - переместить в начало массива точки, лежащие в окружности заданного\n"
           "    радиуса расположенной в начале координат"
           "\n5 - отсортировать массив по расстоянию от начала координат"
           "\n6 - ЗАПИСАТЬ В ФАЙЛ"
           "\n7 - ПРОЧИТАТЬ ИЗ ФАЙЛА (данные в массиве перезапишутся)"
           "\n0 - выйти из меню");
}


int main() {
    system("chcp 65001");
    char do_again;
    short temp, choise, STEP, x1, action;
    float R;

    do
    {
        printf("\nВведите размер массива: ");
        scanf("%d", &temp);
        cleanScanfBuffer();
        if (temp <= 0)
        {
            printf("\nНедопустимый размер.");
            exit(1);
        }

        //создание массива
        const short size = temp;
        Point *array_points = new Point[size];

        printf("\nКак заполнить массив:\n1 - случайные числа\n2 - ввести с клавиатуры\n3 - от x1 с шагом k\nВыбор: ");
        scanf("%d", &choise);
        cleanScanfBuffer();
        switch (choise)
        {
            case 2:
                printf("\nВвод данных с клавиатуры.");
                arrayFillFromKeyboard(array_points, size);
                break;

            case 3:
                printf("\nВведите шаг: ");
                scanf("%d", &STEP);
                printf("\nВведите начальное значение: ");
                scanf("%d", &x1);
                arrayFillStep(array_points, size, x1, STEP);
                break;

            default:
                arrayFillRandomValues(array_points, size);
                break;
        }

        //меню
        action = -1;
        while (action != 0)
        {
            printmenu();
            printf("\nКоманда (цифра): ");
            scanf("%d", &action);
            switch (action)
            {
                case 1:
                    printarray(array_points, size);
                    break;
                case 2:
                    findClosestAndFarestPointsAndChangeTheirPlaces(array_points, size);
                    break;
                case 3:
                    findPointsWithMaxDistanceBetweenThem(array_points, size);
                    break;
                case 4:
                    printf("\nВведите радиус: ");
                    scanf("%f", &R);
                    relocatePointsInSpecificRadiusToTheBeginningOfArray(array_points, size, R);
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                default:
                    break;
            }

        }


        //clean memrory
        delete[] array_points;

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
