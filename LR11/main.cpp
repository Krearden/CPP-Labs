#include <stdio.h>
#include <cstdlib>
#include "Graph.h"
#include "GraphArray.h"


//чистка буфера scanf()
void cleanScanfBuffer()
{
    while ((getchar()) != '\n');
}

//напечатать меню
void printmenu()
{
    printf("\n\nМеню:"
           "\n1 - посмотреть список объектов массива"
           "\n2 - изменить тип графика по индексу"
           "\n3 - изменить свойства графика по индексу"
           "\n4 - напечатать график по индексу"
           "\n0 - выйти из меню");
}

int main() {
    system("chcp 65001");
    char do_again;
    int size, action, graph_index, graph_type_index;
    do
    {
        printf("\nВведите размер массива: ");
        scanf("%d", &size);
        cleanScanfBuffer();

        //инициализация массива графов
        GraphArray graph_array(size);

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
                    graph_array.printElementsInfo();
                    break;
                }
                case 2: {
                    printf("\nИндекс (цифра): ");
                    scanf("%d", &graph_index);
                    printf("\nТип (1 - Sin, 2 - Tg, 3 - Exp): ");
                    scanf("%d", &graph_type_index);
                    graph_array.setGraphType(graph_index, graph_type_index - 1);
                    graph_array.printInfoAboutElement(graph_index);
                    break;
                }
                case 3: {
                    int a, b, c, mashtab_x, mashtab_y;
                    char point;
                    printf("\nИндекс (цифра): ");
                    scanf("%d", &graph_index);
                    printf("\nТекущие свойства графика (%d)\n", graph_index);
                    graph_array.printInfoAboutElement(graph_index);
                    printf("\nПеременная a: ");
                    scanf("%d", &a);
                    printf("\nПеременная b: ");
                    scanf("%d", &b);
                    printf("\nПеременная c: ");
                    scanf("%d", &c);
                    printf("\nПеременная mashtab_x: ");
                    scanf("%d", &mashtab_x);
                    printf("\nПеременная mashtab_y: ");
                    scanf("%d", &mashtab_y);
                    printf("\nПеременная point: ");
                    scanf(" %c", &point);
                    graph_array.setElementsPropertysByIndex(graph_index, a, b, c, mashtab_x, mashtab_y, point);
                    printf("\nОбновленные свойства графика (%d)\n", graph_index);
                    graph_array.printInfoAboutElement(graph_index);
                    break;
                }
                default: {
                    printf("\nИндекс (цифра): ");
                    scanf("%d", &graph_index);
                    graph_array.printInfoAboutElement(graph_index);
                    graph_array[graph_index]->printgraph();
                    break;
                }
            }

        }


        //ask if wank to continue
        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');
    return 0;
}
