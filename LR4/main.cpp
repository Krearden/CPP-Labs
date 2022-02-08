#include <stdio.h>

int main() {
    char do_again;
    unsigned  short int size_one;
    unsigned  short int size_two;

    do
    {
        printf("Введите размер первого и второго массивов через пробел: ");
        scanf("%d %d", &size_one, &size_two);
        int *array_one = new int [size_one];
        int *array_two = new int [size_two];

        printf("Продолжить работу? (y/n): ");
        scanf("%c", &do_again);
    } while (do_again == 'y');

    return 0;
}
