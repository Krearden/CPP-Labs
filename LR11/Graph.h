//
// Created by User on 09.06.2022.
//

#ifndef LR11_GRAPH_H
#define LR11_GRAPH_H

#endif //LR11_GRAPH_H

#include "cmath"
#include <stdio.h>



//базовый класс График  (Graph)
class Graph
{
protected:
    int a, b, c;
    int h;
    float x, y;
    int mashtab_y = 10;
    int mashtab_x = 10;
    char point = '*';
    //virtual functions
    virtual float count_y_value() = 0;
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
    Graph(int a, int b, int c, int mashtab_y)
    {
        set_a(a);
        set_b(b);
        set_c(c);
        setmashtab_y(mashtab_y);
    }
    //setters
    void setmashtab_y(int mashtab_y_to_set)
    {
        if (mashtab_y_to_set > 0)
            this->mashtab_y = mashtab_y_to_set;
        else
            this->mashtab_y = 10;
    }
    void setmashtab_x(int mashtab_x_to_set)
    {
        if (mashtab_x_to_set > 0)
            this->mashtab_x = mashtab_x_to_set;
        else
            this->mashtab_x = 10;
    }
    void setPoint(char point_to_set)
    {
        this->point = point_to_set;
    }
    void set_a(int a_to_set)
    {
        if (a >= -10 && a <= 10)
            this->a = a_to_set;
        else
            this->a = 1;
    }
    void set_b(int b_to_set)
    {
        if (b >= -10 && b <= 10)
            this->b = b_to_set;
        else
            this->b = 1;
    }
    void set_c(int c_to_set)
    {
        if (c >= -10 && c <= 10)
            this->c = c_to_set;
        else
            this->c = 1;
    }
    //getters
    int getmashtab_y()
    {
        return this->mashtab_y;
    }
    int getmashtab_x()
    {
        return this->mashtab_x;
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
        for (x = 0; x < mashtab_x; x += 0.25)
        {
            count_y_value();
            changeH();
            printf("| %5.2lf | %10.7lf | ", x, y);
            for (; this->h > 0; h--)
                printf(" ");
            printf("%c\n", point);

        }
        printf("|-------|------------|\n");
    }
};
//фукнция класса Graph - изменить количество пробелов для печати
void Graph::changeH()
{
    h = y * mashtab_y/2 + mashtab_y/2 + 0.5;
}


//класс GpaphSin
class GraphSin : public Graph {
protected:
    float count_y_value()
    {
        this->y = a * sin(b * x + c);
        return this->y;
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
    GraphSin(int a, int b, int c, int mashtab_y) : Graph(a, b, c, mashtab_y) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->mashtab_y = mashtab_y;
    }
};

//класс GpaphTg
class GraphTg : public Graph
{
protected:
    float count_y_value()
    {
        this->y = a * tan(b * x + c);
        return this->y;
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
    GraphTg(int a, int b, int c, int mashtab_y) : Graph(a, b, c, mashtab_y) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->mashtab_y = mashtab_y;
    }
};

//класс GpaphExp
class GraphExp : public Graph
{
protected:
    float count_y_value()
    {
        this->y = a * exp(b * x);
        return this->y;
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
    GraphExp(int a, int b, int mashtab_y) : Graph(a, b, c, mashtab_y) {
        this->a = a;
        this->b = b;
        this->mashtab_y = mashtab_y;
    }
};