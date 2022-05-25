#include <stdio.h>
#include <cstdlib>
#include "LogicalElementAND.h"

#define MAX_NUMBER_OF_INPUTS 8

//Лабораторная работа 9, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)


//чистка буфера scanf()
void cleanScanfBuffer()
{
    while ((getchar()) != '\n');
}

//define logical "AND" elements in array by hand
void defineElementsByHand(LogicalElementAND *array, unsigned short size)
{
    if (array)
    {
        unsigned short number_of_inputs;
        char string[9];
        for (short i = 0; i < size; i++)
        {
            printf("(%d) Введите количество входов: ", i);
            scanf("%d", &number_of_inputs);
            printf("(%d) Введите знанчения входов через пробел (зн-я ввод. в виде строки типа ""10...""): ", i);
            scanf("%s", &string);
            array[i].setNumberOfInpts(number_of_inputs);
            array[i].setInputsWithString(string);

        }
    }
}

void defineElementsWithStep(LogicalElementAND *array, unsigned short size)
{
    unsigned short okay_array[] = {2, 3, 4, 8};
    unsigned short data_array[MAX_NUMBER_OF_INPUTS];
    short counter = 0;
    for (short i = 0; i < size; i++)
    {
        if (counter == 4)
            counter = 0;
        for (short i = 0; i < okay_array[counter]; i++)
        {
            data_array[i] = rand() % 2;
        }
        array[i].setNumberOfInpts(okay_array[counter]);
        array[i].setInputsWithDataArray(data_array);
        counter++;
    }
}

//напечатать массив
void printarray(LogicalElementAND *array, short size)
{
    printf("|------|----------------------|------------|---------------|\n");
    printf("|  i   |  number of inputs    |  inputs    |  exit signal  |\n");
    printf("|------|----------------------|------------|---------------|\n");

    for (short i = 0; i < size; i++)
    {
        printf("| %4d |                %5d |   %8s |             %d |\n", i, array[i].getNumberOfInputs(), array[i].getInputsAsString(), array[i].findExitSignal());
    }
    printf("|------|----------------------|------------|---------------|\n");
}

//напечатать меню
void printmenu()
{
    printf("\n\nМеню:"
           "\n1 - напечатать массив"
           "\n2 - задать параметры элементов вручную (логические входы вводятся в виде строки типа ""1101..."".)"
           "\n3 - задать параменты элементов с шагом (количество логических входов заполняется с шагом (2->3->4->8)). Сами входы заполняются "
           "      случайными значениями при помощи массива данных типа [1, 1, 0, 1, ... , 0].)"
           "\n0 - выйти из меню");
}



int main() {
    system("chcp 65001");
    char do_again;
    short action, size;

    do
    {
        printf("\nВведите размер массива: ");
        scanf("%d", &size);
        cleanScanfBuffer();

        //создание массива объектов логического "И" без данных
        LogicalElementAND *logical_ands_array = new LogicalElementAND[size];

        //меню
        action = -1;
        while (action != 0)
        {
            printmenu();
            printf("\nКоманда (цифра): ");
            scanf("%d", &action);
            cleanScanfBuffer();
            switch (action)
            {
                case 1:
                    printarray(logical_ands_array, size);
                    break;
                case 2:
                    defineElementsByHand(logical_ands_array, size);
                    break;
                default:
                    defineElementsWithStep(logical_ands_array, size);
                    break;
            }

        }

        //clean memory
        delete[] logical_ands_array;

        //ask if wank to continue
        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
