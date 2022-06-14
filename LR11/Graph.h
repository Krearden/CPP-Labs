//
// Created by User on 09.06.2022.
//

#ifndef LR11_GRAPH_H
#define LR11_GRAPH_H

#endif //LR11_GRAPH_H

#include "cmath";
#include <stdio.h>;



//базовый класс График  (Graph)
class Graph
{
protected:
    int a, b, c;
    int h;
    float x, y;
    int mashtab = 10;
    char point = '*';
    //virtual functions
    virtual int count_y_value() = 0;
    //фукнция - изменить количество пробелов для печати.
    void changeH();
public:
    //конструктор по-умолчанию
    Graph(){this->a = 1; this->b = 1; this->c = 1;}
    //конструктор с параметрами
    Graph(int a, int b, int c)
    {
        set_a(a);
        set_b(b);
        set_c(c);
    }
    Graph(int a, int b, int c, int mashtab)
    {
        set_a(a);
        set_b(b);
        set_c(c);
        setMashtab(mashtab);
    }
    //setters
    void setMashtab(int mashtab)
    {
        if (mashtab > 0)
            this->mashtab = mashtab;
        else
            this->mashtab = 10;
    }
    void setPoint(char point)
    {
        this->point = point;
    }
    void set_a(int a)
    {
        if (a >= -10 && a <= 10)
            this->a = a;
        else
            this->a = 1;
    }
    void set_b(int b)
    {
        if (b >= -10 && b <= 10)
            this->b=b;
        else
            this->b = 1;
    }
    void set_c(int c)
    {
        if (c >= -10 && c <= 10)
            this->c = c;
        else
            this->c = 1;
    }
    //getters
    int getMashtab()
    {
        return this->mashtab;
    }
    char getPoint()
    {
        return this->point;
    }
    int get_a()
    {
        return this->a;
    }
    int get_b()
    {
        return this->b;
    }
    int get_c()
    {
        return this->c;
    }
    //display on graph method
    void printgraph()
    {
        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");
        for (short n = 0; n < 5; n++)
        {

            for (x = 0; x < 4; x += 0.25)
            {
                count_y_value();
                changeH();
                printf("| %5.2lf | %10.7lf | ", (x + n * 4), this->y);
                for (; this->h > 0; this->h--)
                    printf(" ");
                printf("%c\n", this->point);

            }
        }
        printf("|-------|------------|\n");
    }
};
//фукнция класса Graph - изменить количество пробелов для печати
void Graph::changeH()
{
    h = y * mashtab/2 + mashtab/2 + 0.5;
}


//класс GpaphSin
class GraphSin : public Graph {
protected:
    int count_y_value() {
        this->y = a * sin(b * x + c);
    }
public:
    GraphSin() : Graph() {
        this->a = 1;
        this->b = 1;
        this->c = 1;
    }
    GraphSin(int a, int b, int c) : Graph(a, b, c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    GraphSin(int a, int b, int c, int mashtab) : Graph(a, b, c, mashtab) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->mashtab = mashtab;
    }
};

//класс GpaphTg
class GraphTg : public Graph
{
protected:
    int count_y_value()
    {
        this->y = a * tan(b * x + c);
    }
public:
    GraphTg() : Graph() {
        this->a = 1;
        this->b = 1;
        this->c = 1;
    }
    GraphTg(int a, int b, int c) : Graph(a, b, c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    GraphTg(int a, int b, int c, int mashtab) : Graph(a, b, c, mashtab) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->mashtab = mashtab;
    }
};

//класс GpaphExp
class GraphExp : public Graph
{
protected:
    int count_y_value()
    {
        this->y = a * exp(b * x);
    }
public:
    GraphExp() : Graph() {
        this->a = 1;
        this->b = 1;
    }
    GraphExp(int a, int b) : Graph(a, b, c) {
        this->a = a;
        this->b = b;
    }
    GraphExp(int a, int b, int mashtab) : Graph(a, b, c, mashtab) {
        this->a = a;
        this->b = b;
        this->mashtab = mashtab;
    }
};