#include <stdio.h>
#include <cstdlib>


//функция - заполнить массив случайными элементами
void arrayFillRandom(int *array, unsigned short int size)
{
    const short MIN = 1;
    const short MAX = 12;
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

//напечатать массив размера size на экране
void printarray(int *array, unsigned short int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

////напечатать массив размера size на экране
//void printarray(double *array, unsigned short int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        printf("%f ", array[i]);
//    }
//}

//функция - вычислить произведение цифр целого числа
int calculateNumberMultiply(int number)
{
    int answer = 1;
    if (number == 0)
        return 0;
    else
    {
        for(int i = 1; i <= abs(number); i++)
        {
            answer *= i;
        }
        if (number < 0)
        {
            if (abs(number) % 2)
            {
                answer *= -1;
            }
        }
    }

    return answer;
}

int main() {
    system("chcp 65001");
    char do_again;
    short fill_way = 0;
    unsigned short int size;
    int value;
    short STEP;

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
                printf("\nУчтите, что диапазон значений ограничен промежутком [-12 : 12].\nЧтобы избежать ограничений, можно использовать другой тип данных у второго массива, но согласно ТЗ массивы целочисленные.");
                printf("\nВведите шаг: ");
                scanf("%d", &STEP);
                printf("\nВведите начальное значение: ");
                scanf("%d", &value);
                if (value < 0 && abs(value) > 12)
                    continue;
                else if (value * STEP + value > 12)
                    continue;
                else
                {
                    arrayFillStep(array_one, size, value, STEP);
                    break;
                }
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
        printf("\nПереформировать массивы таким образом, чтобы сначала шли все числа меньшие 50, а затем – остальные:");
        int temp_array[size];




        printf("\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);

        delete[] array_one;
        delete[] array_two;
    } while (do_again == 'y');


    system("pause");
    return 0;
}
