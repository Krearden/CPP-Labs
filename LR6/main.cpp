#include <stdio.h>
#include <cstdlib>

//Лабораторная работа 6, вариант № 13
//Выполнил студент 2-го курса физического факультета Запорожченко Кирилл (ФЗ-12)



char* getString(short size)
{
    char *String = new char[size + 1];

    return String;
}


int main() {
    system("chcp 65001");
    char do_again;
    short text_way;
    const char hardcoded_text[] = "Это text, написанный for my program work. Peace.";
    const char file_path[] = "";
    char *String;
    short size;


    do
    {
        FILE *file_pointer = fopen(file_path, "rt");
        printf("\nВыберите источник.\n1 - строка-константа\n2 - ввести с клавиатуры\n3 - прочитать из файла\nВыбор: ");
        scanf("%d", &text_way);
        //выбор источника
        switch (text_way)
        {
            case 1:

                break;
            case 2:
                printf("\nВведите размер строки: ");
                scanf("%d", &size);
                String = getString(size);
                printf("Введите строку с учетом указанного ранее количества символов: ");
                gets(String);

                int x;
                break;
            case 3:
                if (file_pointer == NULL)

                    printf("\nОшибка! Файл не найден");
                else
                {
                    printf("\n(?) Сколько байт прочитать: ");
                    scanf("%d", &size);
                    String = getString(size);
                    fgets(String, size, file_pointer);

                }

                break;
            default:

                break;
        }
        //закрытие файла
        fclose(file_pointer);
        printf("\n\n%s", String);


        //если память под строку была выделена динамически, то очистим её
        if (text_way == 2 || text_way == 3)
            delete[] String;

        printf("\n\nПродолжить работу? (y/n): ");
        scanf(" %c", &do_again);
    } while (do_again == 'y');

    return 0;
}
