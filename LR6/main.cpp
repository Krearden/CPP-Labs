#include <stdio.h>
#include <cstdlib>
#include <string.h>

//Лабораторная работа 6, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)

#define STRING_SIZE 240

int main() {
    system("chcp 65001");
    char do_again;
    short text_way;
    const char hardcoded_string[] = "Это text, написанный for my program work. Peace.";
    const char file_path[] = R"(C:\Users\User\Documents\CLionProjects\CPP-Labs\LR6\input.txt)";
    char String[STRING_SIZE + 1];

    do
    {
        FILE *file_pointer = fopen(file_path, "rt");
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
                if (file_pointer == NULL)
                    printf("\nОшибка! Файл не найден");
                else
                {

                    fgets(String, sizeof(String), file_pointer);
                }
                break;

            default:
                strcpy(String, hardcoded_string);
                break;
        }



        //закрытие файла
        fclose(file_pointer);

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
