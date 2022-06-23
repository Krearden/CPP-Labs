#include <stdio.h>
#include "iostream"
#include "Queue.h"
#include "LogicalElementAND.h"


//Лабораторная работа 12, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)


//напечатать меню
void printmenu()
{
    printf("\n\nМеню:"
           "\n1 - создать очередь типа int и продемонстрировать возможности"
           "\n2 - создать очередь типа LogicalElementAND и продемонстрировать возможности"
           "\n3 - вручную задать очередь, выбрать тип и размер, вывести на экран"
           "\n0 - выйти из меню");
}


int main() {
    system("chcp 65001");
    char do_again;
    short action;

    do
    {
        //меню
        action = -1;
        while (action != 0)
        {
            printmenu();
            printf("\nКоманда (цифра): ");
            scanf("%d", &action);
            switch (action)
            {
                case 1: {
                    Queue<int> queue_numbers;
                    Queue<int> queue_numbers_2(12);
                    printf("\nДобавляю элементы - чиста с 1го до 5ти.");
                    queue_numbers.push(1);
                    queue_numbers.push(2);
                    queue_numbers.push(3);
                    queue_numbers.push(4);
                    queue_numbers.push(5);
                    printf("\nПечатаю очередь queue_numbers:");
                    queue_numbers.printqueue();
                    printf("\nДважды выполняю .pop(), первые двое вошедших в очередь из нее выходят.");
                    queue_numbers.pop();
                    queue_numbers.pop();
                    printf("\nПечатаю очередь queue_numbers:");
                    queue_numbers.printqueue();
                    printf("\nКопирую очередь queue_numbers в queue_numbers_2 с помощью перезагруженного оператора равенства:");
                    queue_numbers_2 = queue_numbers;
                    printf("\nПечатаю очередь queue_numbers_2:");
                    queue_numbers_2.printqueue();

                    break;
                }
                case 2: {
                    const char string_for_logical_two[] = "1111";
                    const char string_for_logical_three[] = "1011";
                    printf("\nИнициализирую три переменные типа LogicalElementAND.");
                    LogicalElementAND logical_one;
                    LogicalElementAND logical_two(4, string_for_logical_two);
                    LogicalElementAND logical_three(4, string_for_logical_three);
                    printf("\nИнициализирую очередь queue_logicaland и доавляю в нее три элемента");
                    Queue<LogicalElementAND> queue_logicaland;
                    queue_logicaland.push(logical_one);
                    queue_logicaland.push(logical_two);
                    queue_logicaland.push(logical_three);
                    printf("\nПечатаю очередь queue_logicaland."
                           "\nТ. к. в классе переопределен оператор ""<<"", выводится будут только выходные сигнланы логического элемента ""И""");
                    queue_logicaland.printqueue();
                    printf("\nОдин раз выполняю .pop(), первый вошедший в очередь элемент из нее выходит.");
                    queue_logicaland.pop();
                    printf("\nПечатаю очередь queue_logicaland.");
                    queue_logicaland.printqueue();
                    printf("\nИнициализирую очередь queue_logicaland_2,\nкопирую в нее элементы из первой очереди с помощью перезагруженного оператора ""="".");
                    Queue<LogicalElementAND> queue_logicaland_2 = queue_logicaland;
                    printf("\nПечатаю очередь queue_logicaland_2.");
                    queue_logicaland_2.printqueue();
                    break;
                }
                case 3: {
                    unsigned int size, element, type;
                    printf("\nВведите размер очереди: ");
                    scanf("%d", &size);
                    printf("\nВведите тип очереди (1 - int, 2 - LogicalElementAND): ");
                    scanf("%d", &type);
                    switch(type)
                    {
                        case 1: {
                            Queue<int> queue_numbers_3(size);
                            for (unsigned int i = 0; i < size; i++)
                            {
                                printf("\nВведите %dй элемент очереди: ", i + 1);
                                scanf("%d", &element);
                                queue_numbers_3.push(element);
                            }
                            queue_numbers_3.printqueue();
                            break;
                        }
                        default: {
                            Queue<LogicalElementAND> queue_logicaland_3(size);
                            unsigned short array[4];
                            LogicalElementAND logical_four;
                            for (unsigned int i = 0; i < size; i++)
                            {
                                for (unsigned int i = 0; i < 4; i++)
                                {
                                    array[i] = rand() % 2;
                                }
                                logical_four.setNumberOfInpts(4);
                                logical_four.setInputsWithDataArray(array);
                                queue_logicaland_3.push(logical_four);
                            }
                            queue_logicaland_3.printqueue();
                            break;
                        }
                    }
                }
            }

        }


        //ask if wank to continue
        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
