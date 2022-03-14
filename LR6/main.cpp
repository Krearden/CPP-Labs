#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>

//Лабораторная работа 6, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)

#define STRING_SIZE 240
#define MASHTAB 5

void fillAlphabetCountArrayWithLetterCountData(char *String, short *engAlphabetCount)
{
    short i = 0, temp, index;
    while (String[i])
    {
        //преобразуем символ к верхнему регистру
        String[i] = toupper(String[i]);
        //temp - Dec код символа
        temp = (unsigned char)String[i];
        if (temp > 64 && temp < 91)
        {
            index = temp - 65;
            engAlphabetCount[index] += 1;
        }
        i++;
    }
}

void changeH(short& h, short letter_count, short mashtab)
{
        h = letter_count  * mashtab + 0.5;
}

//найти первое не нулевое значение в массиве
short findFirstNonZeroValueOfArray(short *engAlphabetCount)
{
    for (short i = 0; i < 26; i++)
    {
        if (engAlphabetCount[i] != 0)
            return i;
    }
    return 0;
}

int main() {
    system("chcp 65001");
    char do_again;
    short text_way, h;
    const char hardcoded_string[] = "Это text, написанный for my program work. Peace.";
    const char engAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    short engAlphabetCount[26] = {0};
    const char input_file_path[] = R"(C:\Users\User\Documents\CLionProjects\CPP-Labs\LR6\input.txt)";
    const char output_file_path[] = R"(C:\Users\User\Documents\CLionProjects\CPP-Labs\LR6\output.txt)";
    char String[STRING_SIZE + 1];

    do
    {
        FILE *input_file_pointer = fopen(input_file_path, "rt");
        FILE *output_file_pointer = fopen(output_file_path, "wt");
        printf("\nВыберите источник.\n1 - строка-константа\n2 - ввести с клавиатуры\n3 - прочитать из файла\nВыбор: ");
        scanf("%d", &text_way);
        //уберем '\n' из буфера, чтобы сработал fgets()
        while ((getchar()) != '\n');

        //выбор источника
        switch (text_way)
        {
            case 2:
                printf("Введите строку с учетом указанного ранее количества символов (%d): ", STRING_SIZE);
                fgets(String, sizeof(String), stdin);
                break;

            case 3:
                if (input_file_pointer == NULL)
                    printf("\nОшибка! Файл не найден");
                else
                {

                    fgets(String, sizeof(String), input_file_pointer);
                }
                break;

            default:
                strcpy(String, hardcoded_string);
                break;
        }

        //заполняем массивы (i-й элемент одного соотв. i-тому элементу другого)
        fillAlphabetCountArrayWithLetterCountData(String, engAlphabetCount);
        //вывод на экран
        printf("\nНиже представлена таблица количества букв в строке и гитрограмма, репрезентирующая это количество.");
        printf("\nСтрока, выбранная для работы: «%s»", String);
        printf("\n|----------------|");
        printf("\n| Letter | Count |");
        printf("\n|--------|-------|");
        //запись в файл
        fprintf(output_file_pointer, "\nНиже представлена таблица количества букв в строке и гитрограмма, репрезентирующая это количество.");
        fprintf(output_file_pointer, "\nСтрока, выбранная для работы: «%s»", String);
        fprintf(output_file_pointer, "\n|----------------|");
        fprintf(output_file_pointer, "\n| Letter | Count |");
        fprintf(output_file_pointer, "\n|--------|-------|");

        for (short i = 0; i < 26; i++)
        {
            if (engAlphabetCount[i] != 0)
            {
                changeH(h, engAlphabetCount[i], MASHTAB);
                printf("\n| %6c | %5d |", engAlphabet[i], engAlphabetCount[i]);
                fprintf(output_file_pointer, "\n| %6c | %5d |", engAlphabet[i], engAlphabetCount[i]);
                for (; h > 0; h--)
                {
                    printf("=");
                    fprintf(output_file_pointer, "=");
                }
            }
        }
        printf("\n|----------------|");
        fprintf(output_file_pointer, "\n|----------------|");

        //закрытие файлов
        fclose(input_file_pointer);
        fclose(output_file_pointer);

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
