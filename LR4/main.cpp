#include <stdio.h>
#include <cstdlib>
#include <float.h>

//Лабораторная работа 4, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)
//Задание: 13. Написать программу для работы с двумя целочисленными массивами.


//функция - заполнить массив случайными элементами
void arrayFillRandom(int *array, unsigned short int size)
{
    const short MIN = -100;
    const short MAX = 100;
    for (int i = 0; i < size; i++)
        array[i] = MIN + rand()%(MAX - MIN + 1);
}


//заполнить массив по порядку от x1 с шагом k
void arrayFillStep(int *array, unsigned short int size, int value, short STEP)
{

    for (int i = 0; i < size; i++)
    {
        array[i] = value;
        value += STEP;
    }
}

//напечатать массив размера size на экране (int)
void printarray(int *array, unsigned short int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("[Адрес начала 0x%X]", array);
}

//напечатать массив размера size на экране (double)
void printarray(double *array, unsigned short int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%6.0f ", array[i]);
    }
    printf("[Адрес начала 0x%X]", array);
}


//функция - вычислить произведение цифр, составляющих число
int calculateNumberMultiply(int number)
{
    int answer = 1;
    short sign = 1;
    if (number == 0)
        return 0;
    if (number < 0)
        sign = -1;
    number = abs(number);
    while (number != 0)
    {
        answer *= number % 10;
        number /= 10;
    }

    return answer * sign;
}

//поменять местами элементы массива
void swap_items(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

//метод для задания "Переформировать массивы таким образом, чтобы сначала шли все числа меньшие 50, а затем – остальные"
void reformArray(int *array, unsigned short int size)
{
    for (short i = 0; i < size; i++)
    {
        if (array[i] > 50)
        {
            for (short j = i + 1; j < size; j++)
            {
                if (array[j] < 50)
                    swap_items(array[i], array[j]);
            }
        }
    }
}

//найти минимальный элемент массива
double findMinItem(double *array, unsigned short size)
{
    double min_pr = DBL_MAX;
    for (short i = 0; i < size; i++)
    {
        if (array[i] < min_pr)
            min_pr = array[i];
    }

    return min_pr;
}

//найти максимальный элемент массива
double findMaxItem(double *array, unsigned short size)
{
    double max_pr = DBL_MIN;
    for (short i = 0; i < size; i++)
    {
        if (array[i] > max_pr)
            max_pr = array[i];
    }

    return max_pr;
}

//найти среднее арифм. эл. массива
double findAvg(double *array, unsigned short size)
{
    double sum = 0;
    for (short i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum / size;
}

int main() {
    system("chcp 65001");
    char do_again;
    short fill_way = 0;
    unsigned short int size;
    int value;
    short STEP;
    double min, max, avg;

    do
    {
        printf("\nВведите размер первого и второго массивов: ");
        scanf("%d", &size);
        if (size == 0)
            exit(0);
        int *array_one = new int [size];
        int *array_two = new int [size];
        printf("\nКаким способом заполнить первый массив? (1 - random, 2 - от x1 c шагом k): ");
        scanf("%d", &fill_way);
        //заполнить первый массив 1 или 2 способом
        switch (fill_way)
        {
            case 1:
                arrayFillRandom(array_one, size);
                break;
            case 2:
                printf("\nВведите шаг: ");
                scanf("%d", &STEP);
                printf("\nВведите начальное значение: ");
                scanf("%d", &value);
                arrayFillStep(array_one, size, value, STEP);
                break;
            default:
                arrayFillRandom(array_one, size);
                break;
        }
        printf("\nЗаполненный массив 1: ");
        printarray(array_one, size);

        //заполнить 2-й массив
        for (int i = 0; i < size; i++)
        {
            array_two[i] = calculateNumberMultiply(array_one[i]);
        }
        printf("\nЗаполненный массив 2: ");
        printarray(array_two, size);

        //Переформировать массивы таким образом, чтобы сначала шли все числа меньшие 50, а затем – остальные
        //фильтруем только второй массив, т.к. в первом не может быть чисел вне предела [-12 : 12]
        printf("\n\nПереформировать массивы таким образом, чтобы сначала шли все числа меньшие 50, а затем – остальные:");
        reformArray(array_one, size);
        reformArray(array_two, size);
        printf("\nПереформированный массив 1: ");
        printarray(array_one, size);
        printf("\nПереформированный массив 2: ");
        printarray(array_two, size);

        //Находить максимальное, минимальное и среднее значения произведений
        //соответствующих элементов первого и второго массивов
        printf("\n\nНаходить макс., мин. и ср. знач. произведений соответствующих элементов 1-го и 2-го массивов:");
        double array_multiply[size];
        for (short i = 0; i < size; i++)
        {
            array_multiply[i] = array_one[i] * array_two[i];
        }
        printf("\nМассив произведений: ");
        printarray(array_multiply, size);
        //find min
        min = findMinItem(array_multiply, size);
        printf("\nМин. значение произведения i-тых членов: %6.0f", min);
        //find max
        max = findMaxItem(array_multiply, size);
        printf("\nМакс. значение произведения i-тых членов: %6.0f", max);
        //find average
        avg = findAvg(array_multiply, size);
        printf("\nСред. значение произведения i-тых членов: %6.5f", avg);

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);

        delete[] array_one;
        delete[] array_two;
    } while (do_again == 'y');


    system("pause");
    return 0;
}
