#include <stdio.h>
#include <conio.h>
#include <cstdlib>

//Лабораторная работа 2, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)

int getFormulaOneValue(int x, int y, int z)
{
    x *= y + z;

    return x;
}

int getFormulaTwoValue (int x, int y, int z)
{
    //проверка. на ноль делить нельзя.
    if (y != 0 && z != 0)
        x = x / y || x / z;
    //возвращает 0, если сравниваются 2 нуля и 1, если сравниваются 2 целых числа
    return x;
}

float getFormulaOneValue(float fx, float fy, float fz)
{
    fx *= fy + fz;

    return fx;
}

void changeResultValue(int& result, int x, int y, int z, int formula_number = 1)
{
    if (formula_number == 1)
        result = getFormulaOneValue(x, y, z);
    else if (formula_number == 2)
        result = getFormulaTwoValue(x, y, z);
}

void changeFResultValue(float& fresult, float x, float y, float z)
{
    fresult = getFormulaOneValue(x, y, z);
}

int main() {
    system("chcp 65001");

    int xyz_values[9] = {0, 0, 0,0, 0, 0, 0, 0 ,0};
    float fxyz_values[9] = {0.0, 0.0, 0.0,0.0, 0.0, 0.0, 0.0, 0.0,0.0};
    int counter;

    printf("\nЗадание 1.\n");
    //заполнение массива значениями x, y, z
    counter = 0;
    for (int i = 1; i <= 3; i++)
    {
        printf("(%d) Введите значения для переменных x, y, z через запятую с пробелом: ", i);
        scanf("%d, %d, %d", &xyz_values[counter], &xyz_values[counter + 1], &xyz_values[counter + 2]);
        counter += 3;
    }

    //табличка для первой формулы
    int result = getFormulaOneValue(xyz_values[0], xyz_values[1], xyz_values[2]);
    printf("|--------------------------------------|\n");
    printf("|   x   |   y   |   z   |  x *= y + z  |\n");
    printf("|-------|-------|-------|--------------|\n");
    counter = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("|  %3d  |  %3d  |  %3d  |  %10d  |\n", xyz_values[counter], xyz_values[counter + 1], xyz_values[counter + 2], result);
        counter += 3;
        changeResultValue(result,xyz_values[counter], xyz_values[counter + 1], xyz_values[counter + 2]);
    }
    printf("|-------|-------|-------|--------------|\n");

    //табличка для второй формулы
    changeResultValue(result, xyz_values[0], xyz_values[1], xyz_values[2], 2);
    printf("|------------------------------------------|\n");
    printf("|   x   |   y   |   z   |  x / y || x / z  |\n");
    printf("|-------|-------|-------|------------------|\n");
    counter = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("|  %3d  |  %3d  |  %3d  |  %14d  |\n", xyz_values[counter], xyz_values[counter + 1], xyz_values[counter + 2], result);
        counter += 3;
        changeResultValue(result,xyz_values[counter], xyz_values[counter + 1], xyz_values[counter + 2], 2);
    }
    printf("|-------|-------|-------|------------------|\n");



    printf("\n\nЗадание 2.\n");
    //заполнение массива значениями fx, fy, fz
    counter = 0;
    for (int i = 1; i <= 3; i++)
    {
        printf("(%d) Введите значения для переменных fx, fy, fz через пробел: ", i);
        scanf("%f  %f  %f", &fxyz_values[counter], &fxyz_values[counter + 1], &fxyz_values[counter + 2]);
        counter += 3;
    }
    printf("\n");
    float fresult = getFormulaOneValue(fxyz_values[0], fxyz_values[1], fxyz_values[2]);
    printf("|-----------------------------------------------|\n");
    printf("|      x   |      y   |      z   |  x *= y + z  |\n");
    printf("|----------|----------|----------|--------------|\n");
    counter = 0;
    //int k  = 1 + 13 % 5 = 4; (точность для вывода, не разобрался, как исползьовать переменную k в модификаторе точности).
    for (int i = 0; i < 3; i++)
    {
        printf("|  %6.2f  |  %6.2f  |  %6.2f  |  %10.4f  |\n", fxyz_values[counter], fxyz_values[counter + 1], fxyz_values[counter + 2], fresult);
        counter += 3;
        changeFResultValue(fresult, fxyz_values[counter], fxyz_values[counter + 1], fxyz_values[counter + 2]);
    }
    printf("|----------|----------|----------|--------------|\n");

    getch();
    return 0;
}
