#include <stdio.h>
#include <cstdlib>

//Лабораторная работа 5, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)


//заполнить массив по возрастанию
void fillArrayInAscendingOrder(int **DArray, short N)
{
    int value = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            DArray[i][j] = value;
            value++;
        }
    }
}

//заполнить массив случайными значениями
void fillArrayRandomValues(int **DArray, short N)
{
    const short MIN = -100;
    const short MAX = 100;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            DArray[i][j] = MIN + rand()%(MAX - MIN + 1);
        }
    }
}

//заполнить средний ряд суммами
void fillArrayCenterLineSum(int **DArray, short N)
{
    int temp_sum = 0;
    for (short i = 0; i < N; i++)
    {
        for (short j = 0; j < N; j++)
        {
            if (i != j)
            {
                temp_sum += DArray[i][j];
                temp_sum += DArray[j][i];
            }
        }
        DArray[i][i] = temp_sum;
        temp_sum = 0;
    }
}

//вывести массив на экран
void printarray(int **DArray, short N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%3d ", DArray[i][j]);
        printf("\n");
    }
}

//напечатать меню
void printmenu()
{
    printf("\n\nМеню:\n1 - напечатать массив\n2 - вывести адреса переменных\n3 - вывести адреса массива\n0 - выйти из меню");
}

int main() {
    system("chcp 65001");
    char do_again;
    short temp, fill_way, action;

    do
    {
        printf("\nВведите размерность массива (N): ");
        scanf("%d", &temp);
        if (temp <= 0)
        {
            printf("\nНедопустимый размер.");
            exit(1);
        }
        //выделение памяти под двумерный массив
        const short N = temp;
        int **DArray = new int *[N];

        for (short i = 0; i < N; i++)
        {
            DArray[i] = new int [N];
        }

        printf("\nКаким способом заполнить двумерный массив? (1 - по возрастанию, 2 - random): ");
        scanf("%d", &fill_way);
        //заполнить первый массив 1 или 2 способом (1 - по возрастанию, 2 - random)
        switch (fill_way)
        {
            case 1:
                int x;
                fillArrayInAscendingOrder(DArray, N);
                fillArrayCenterLineSum(DArray, N);
                break;
            case 2:
                fillArrayRandomValues(DArray, N);
                fillArrayCenterLineSum(DArray, N);
                break;
            default:
                fillArrayInAscendingOrder(DArray, N);
                fillArrayCenterLineSum(DArray, N);
                break;
        }
        printf("\nМассив заполнен. Выберите команду из меню. (0 - выйти)");

        while (action != 0)
        {
            printmenu();
            printf("\nКоманда (цифра): ");
            scanf("%d", &action);
            switch (action)
            {
                case 1:
                    printarray(DArray, N);
                    break;
                case 2:
                    printf("\nАдреса переменных: ");
                    printf("\nАдрес переменной do_again = 0x%X", &do_again);
                    printf("\nАдрес переменной N = 0x%X", &N);
                    printf("\nАдрес переменной fill_way = 0x%X", &fill_way);
                    printf("\nАдрес переменной action = 0x%X", &action);
                    break;
                case 3:
                    printf("\nАдрес DArray = 0x%X\n", DArray);
                    for (short i = 0; i < N; i++)
                        printf("Адрес указателя DArray[%d] = 0x%X, Адрес строки DArray[%d] = 0x%X\n", i, DArray[i], i, &DArray[i]);
                    break;
            }

        }

        //освобождаем память после работы программы
        for (short i = 0; i < N; i++)
            delete[] DArray[i];
        delete[] DArray;

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
