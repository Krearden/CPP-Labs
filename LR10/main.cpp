#include <stdio.h>
#include <cstdlib>
#include "LogicalElementAND.h"
#include "iostream"

#define MAX_NUMBER_OF_INPUTS 8

//Лабораторная работа 10, вариант № 13
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

//print info about specified element
void printElementinfo(LogicalElementAND element)
{
    printf("\n|----------------------|------------|---------------|\n");
    printf("|  number of inputs    |  inputs    |  exit signal  |\n");
    printf("|----------------------|------------|---------------|\n");
    printf("|                %5d |   %8s |             %d |\n", element.getNumberOfInputs(), element.getInputsAsString(), element.findExitSignal());
    printf("|----------------------|------------|---------------|\n");
}

//напечатать меню
void printmenu()
{
    printf("\n\nМеню:"
           "\n1 - напечатать массив"
           "\n2 - задать параметры элементов вручную (логические входы вводятся в виде строки типа ""1101..."".)"
           "\n3 - задать параменты элементов с шагом (количество логических входов заполняется с шагом (2->3->4->8)). "
           "\n    Сами входы заполняются случайными значениями при помощи массива данных типа [1, 1, 0, 1, ... , 0].)"
           "\n4 - демонстрация функционала (все конструкторы и сравнение объектов)"
           "\n5 - Демонтрация работы перезагруженных операторов (LR10)"
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
                case 1: {
                    printarray(logical_ands_array, size);
                    break;
                }
                case 2: {
                    defineElementsByHand(logical_ands_array, size);
                    break;
                }
                case 3: {
                    defineElementsWithStep(logical_ands_array, size);
                    break;
                }
                case 4: {
                    //создание элемента с конструктором для задания логических входов Строкой
                    const char string[] = "1111";
                    LogicalElementAND logical_one(4, string);
                    //создание элемента с конструктором для задания логических входов Массивом данных
                    unsigned short data_array[] = {1, 0};
                    LogicalElementAND logical_two(2, data_array);
                    printf("\nElement ""logical_one"":");
                    printElementinfo(logical_one);
                    printf("\nElement ""logical_two"":");
                    printElementinfo(logical_two);
                    //логические операции сравнения
                    bool equal, is_grater, is_lesser;
                    equal = logical_one == logical_two;
                    is_grater = logical_one > logical_two;
                    is_lesser = logical_one < logical_two;
                    printf("\nПерезагруженные логические операции над элементами:");
                    printf("\nlogical_one == logical_two: %s", equal ? "True" : "False");
                    printf("\nlogical_one > logical_two: %s", is_grater ? "True" : "False");
                    printf("\nlogical_one < logical_two: %s", is_lesser ? "True" : "False");
                    break;
                }
                default: {
                    //создание элемента для демонстрации
                    unsigned short data_array_for_element_three[] = {1, 0};
                    LogicalElementAND logical_three(2, data_array_for_element_three);
                    LogicalElementAND logical_four;
                    printf("\n\nElement ""logical_three"":");
                    printElementinfo(logical_three);
                    printElementinfo(logical_four);
                    //[]
                    printf("\n\nДемонстация оператора []");
                    printf("\nlogical_three[0] = %d", logical_three[0]);
                    //=
                    printf("\n\nДемонстация оператора =");
                    printf("\nlogical_four = logical_three");
                    logical_four = logical_three;
                    printElementinfo(logical_four);
                    printf("\n\nДемонстация оператора >>");
                    std::cin >> logical_four;
                    printf("\n\nДемонстация оператора <<");
                    std::cout << logical_four;
                    break;
                }
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
