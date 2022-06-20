//
// Created by User on 14.06.2022.
//

#ifndef LR11_GRAPHARRAY_H
#define LR11_GRAPHARRAY_H

#endif //LR11_GRAPHARRAY_H


#include <typeinfo>
#include <string.h>

class GraphArray
{
private:
    Graph **Array; //указатель на массив указателей
    unsigned int size;
    enum {SIN, TG, EXP};
public:
    //конструкторы
    GraphArray() {size = 0; Array = 0;} //default constructor
    GraphArray(unsigned int size_to_set)
    {
        Array = nullptr;
        setArraySize(size_to_set);
    }

    //methods, getters, setters
    void setArraySize(unsigned int size_to_set)
    {
        Clear();
        size = size_to_set;
        Array = new Graph*[size];
        for (unsigned int i = 0; i < size; i++)
            Array[i] = new GraphSin;

    }
    unsigned int getArraySize() const
    {
        return this->size;
    }
    void Clear()
    {
        if (Array)
        {
            for (unsigned int i = 0; i < size; i++)
            {
                if (Array[i])
                    delete Array[i];
            }
            delete[] Array;
            size = 0;
            Array = nullptr;
        }
    }
    //don't work correctly?
    void setGraphType(unsigned int i, unsigned int type)
    {
        if (i >= 3)
            throw 11; //will fix this later неверный тип
        if (i < size)
        {
            if (Array[i])
                delete Array[i];
            switch (type)
            {
                case SIN: {
                    Array[i] = new GraphSin;
                    break;
                }
                case TG: {
                    Array[i] = new GraphTg;
                    break;
                }
                case EXP: {
                    Array[i] = new GraphExp;
                    break;
                }
            }
        }
        else
        {
            throw 10; //will fix this later выход за пределы массива
        }
    }
    //set element's propertys by index
    void setElementsPropertysByIndex(int index, int a, int b, int c, int mashtab_x, int mashtab_y, char point)
    {
        Array[index]->set_a(a);
        Array[index]->set_b(b);
        Array[index]->set_c(c);
        Array[index]->setmashtab_x(mashtab_x);
        Array[index]->setmashtab_y(mashtab_y);
        Array[index]->setPoint(point);
    }
    //get graph type sin || tg || exp
    unsigned int getGraphType(unsigned int i)
    {
        if (typeid(*(Array[i])) == typeid(GraphSin)) return SIN;
        if (typeid(*(Array[i])) == typeid(GraphTg)) return TG;
        if (typeid(*(Array[i])) == typeid(GraphExp)) return EXP;
        throw 13; //will fix this later Неизвестный тип
    }
    //print info about array elements
    void printElementsInfo()
    {
        unsigned int type;
        char graph_type[4];
        printf("|------|--------|-----|-----|-----|-------------|-------------|\n");
        printf("|  i   |  Type  |  a  |  b  |  c  |  mashtab_x  |  mashtab_y  |\n");
        printf("|------|--------|-----|-----|-----|-------------|-------------|\n");

        for (short i = 0; i < size; i++)
        {
            type = getGraphType(i);
            switch (type)
            {
                case 0:
                    strcpy(graph_type, "Sin");
                    break;
                case 1:
                    strcpy(graph_type, "Tg");
                    break;
                case 2:
                    strcpy(graph_type, "Exp");
                    break;
            }
            printf("| %4d | %6s |  %d  |  %d  |  %d  |         %d  |         %d  |\n", i, graph_type, Array[i]->get_a(), Array[i]->get_b(), Array[i]->get_c(), Array[i]->getmashtab_x(), Array[i]->getmashtab_y());
        }
        printf("|------|--------|-----|-----|-----|-------------|-------------|\n");
    }
    //print specific element
    void printInfoAboutElement(int i)
    {
        if (i < size)
        {
            unsigned int type;
            char graph_type[4];
            printf("|------|---  ---|-----|-----|-----|-------------|-------------|\n");
            printf("|  i   |  Type  |  a  |  b  |  c  |  mashtab_x  |  mashtab_y  |\n");
            printf("|------|---  ---|-----|-----|-----|-------------|-------------|\n");

            type = getGraphType(i);
            switch (type)
            {
                case 0:
                    strcpy(graph_type, "Sin");
                    break;
                case 1:
                    strcpy(graph_type, "Tg");
                    break;
                case 2:
                    strcpy(graph_type, "Exp");
                    break;
            }
            printf("| %4d | %6s |  %d  |  %d  |  %d  |         %d  |         %d  |\n", i, graph_type, Array[i]->get_a(), Array[i]->get_b(), Array[i]->get_c(), Array[i]->getmashtab_x(), Array[i]->getmashtab_y());

            printf("|------|---  ---|-----|-----|-----|-------------|-------------|\n");
        }
        else
            throw 10; //will fix this later выход за пределы массива
    }

    //reload operators
    GraphArray& operator=(GraphArray &element_to_copy_from)
    {
        if(this == &element_to_copy_from) return *this;
        Clear();
        this->setArraySize(element_to_copy_from.size);
        for (unsigned int i = 0; i < size; i++)
        {
            this->setGraphType(i, element_to_copy_from.getGraphType(i));
            *(Array[i]) = *(element_to_copy_from.Array[i]);
        }
        return *this;
    }
    Graph* operator[](unsigned int i)
    {
        if (i < size)
        {
            if(Array[i])
                return Array[i];
            throw 12; //will fix this later i-я фигура не существует
        }
        throw 10; //will fix this later выход за пределы массива
    }
};
