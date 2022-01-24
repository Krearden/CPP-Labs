#include <iostream>
#include <string>


//LR1
//С клавиатуры вводятся два целых числа [0-4].
//Вывести на экран результат умножения словами
//(например, для чисел 2 и 2 должнобыть выведено: «два умножить на два равно четыре»).

using namespace std;

string getWord(int number)
{
    string word;
    switch(number)
    {
        case 0:
            word = "ноль";
            break;
        case 1:
            word = "один";
            break;
        case 2:
            word = "два";
            break;
        case 3:
            word = "три";
            break;
        case 4:
            word = "четыре";
            break;
        case 5:
            word = "пять";
            break;
        case 6:
            word = "шесть";
            break;
        case 7:
            word = "семь";
            break;
        case 8:
            word = "восемь";
            break;
        case 9:
            word = "девять";
            break;
        case 10:
            word = "десять";
            break;
        case 11:
            word = "одиннадцать";
            break;
        case 12:
            word = "двенадцать";
            break;
        case 13:
            word = "тринадцать";
            break;
        case 14:
            word = "четырнадцать";
            break;
        case 15:
            word = "пятнадцать";
            break;
        case 16:
            word = "шестнадцать";
            break;
    }

    return word;
}

int main() {
    system("chcp 65001");
    int a, b;
    string a_word;
    string b_word;

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    if (a < 0 || a > 4 || b < 0 || b > 4)
    {
        cout << "Ошибка. Недопустимое значение переменной." << "\n";
        system("pause");
        exit(1);
    }

    a_word = getWord(a);
    b_word = getWord(b);

    cout << "\n" << a_word << " умножить на " << b_word << " равно " << " " << getWord(a * b) << "\n";

    system("pause");
    return 0;
}
