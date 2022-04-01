#include <stdio.h>
#include <cstdlib>


//Лабораторная работа 7, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)

#define BINARY_STRING_LENGTH 16

//заполнить массив случайными значениями
void fillArrayRandomValues(unsigned short *array, short N)
{
    const unsigned short MIN = 0;
    const unsigned short MAX = 65535; //макс. число, помещающееся в два байта
    for (int i = 0; i < N; i++)
    {
        array[i] = MIN + rand()%(MAX - MIN + 1);
    }
}

////заполнить массив с клавиатуры
//void fillArrayFromKeyboard(unsigned short *array, short N)
//{
//    short counter = 1;
//    int number;
//
//    while (counter <= N)
//    {
//        printf("\nВведите число (%d из %d): ", counter, N);
//        scanf("%d", &number);
//        if (number >= 0 && number <= 65535)
//            array[counter - 1] = number;
//        else
//        {
//            printf("\nНедопустимое число. Повторите ввод.");
//            continue;
//        }
//        counter++;
//    }
//}

//заполнить массив по порядку от x1 с шагом k
void arrayFillStep(unsigned short *array, unsigned short int size, int value, short STEP)
{

    for (int i = 0; i < size; i++)
    {
        array[i] = value;
        value += STEP;
    }
}

void changeBinaryRepresentationString(char *binary_representation, unsigned short number)
{
    unsigned short MASK = 0x8000;
    for (short i = 0; i < BINARY_STRING_LENGTH; i++)
    {
        if (number & MASK) {
            binary_representation[i] = '1';
        }
        else {
            binary_representation[i] = '0';
        }
        MASK >>= 1;
    }
}

//вывести массив на экран
void printarray(unsigned short *array, short N)
{
    char binary_representation[BINARY_STRING_LENGTH]  = {0};
    binary_representation[BINARY_STRING_LENGTH] = '\0';
    printf("|------------------------|------------------|--------|\n");
    printf("|  i |        a_i        |      binary      |  hex   |\n");
    printf("|----|-------------------|------------------|--------|\n");
    for (int i = 0; i < N; i++)
    {
        changeBinaryRepresentationString(binary_representation, array[i]);
        printf("| %2d | %17d | %s | 0x%-4X |\n", i, array[i], binary_representation, array[i]);
    }
    printf("|------------------------|------------------|--------|\n");
}

//посчитать количество единичных битов числа
short countBitsOfNumber(unsigned short number)
{
    short counter = 0;
    while (number)
    {
        if (number & 1)
            counter++;
        number = number >> 1;
    }

    return counter;
}

//напечатать меню
void printmenu()
{
    printf("\n\nМеню:"
           "\n1 - напечатать первый  массив"
           "\n2 - напечатать второй массив"
           "\n3 - напечатать подсчет битов элементов 1-го массива"
           "\n4 - напечатать подсчет битов элементов 2-го массива"
           "\n0 - выйти из меню");
}

int main() {
    system("chcp 65001");
    char do_again;
    short temp, fill_way, STEP, x1;
    short action = 1;

    do
    {
        printf("\nВведите размер массива: ");
        scanf("%d", &temp);
        if (temp <= 0)
        {
            printf("\nНедопустимый размер.");
            exit(1);
        }

        //создание массива
        const short N = temp;
        unsigned short *array = new unsigned short[N];

        printf("\nКаким способом заполнить двумерный массив? (1 - random, 2 - от x1 с шагом k): ");
        scanf("%d", &fill_way);

        //заполнить первый массив 1 или 2 способом (1 - по возрастанию, 2 - от x1 с шагом k)
        if (fill_way == 1)
            fillArrayRandomValues(array, N);
        else
        {
            printf("\nВведите шаг: ");
            scanf("%d", &STEP);
            printf("\nВведите начальное значение: ");
            scanf("%d", &x1);
            arrayFillStep(array, N, x1, STEP);
        }

        //заполним второй массив в соотв. с заданием
        short allowed_count_of_bits_counter = 0;
        short counter = 0;
        for (short i = 0; i < N; i++)
        {
            if (countBitsOfNumber(array[i]) % 3 != 0)
                allowed_count_of_bits_counter++;
        }
        unsigned short second_array[allowed_count_of_bits_counter];
        for (short i = 0; i < N; i++)
        {
            if (countBitsOfNumber(array[i]) % 3 != 0)
            {
                second_array[counter] = array[i];
                counter++;
            }
        }



        //меню
        while (action != 0)
        {
            printmenu();
            printf("\nКоманда (цифра): ");
            scanf("%d", &action);
            switch (action)
            {
                case 1:
                    printf("\nПервый (изначальный) массив.\n");
                    printarray(array, N);
                    break;
                case 2:
                    printf("\nВторой массив.\n");
                    printarray(second_array, allowed_count_of_bits_counter);
                    break;
                case 3:
                    printf("\nПервый (изначальный массив).\n");
                    for (short i = 0; i < N; i++)
                    {
                        printf("\na[i] = %d; Count of bits = %d", array[i], countBitsOfNumber(array[i]));
                    }
                    break;
                case 4:
                    printf("\nВторой массив.\n");
                    for (short i = 0; i < allowed_count_of_bits_counter; i++)
                    {
                        printf("\na[i] = %d; Count of bits = %d", second_array[i], countBitsOfNumber(array[i]));
                    }
                    break;
                default:
                    break;
            }

        }

        //освобождаем память
        delete[] array;

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
