//
// Created by User on 14.06.2022.
//

#ifndef LR11_GRAPHARRAY_H
#define LR11_GRAPHARRAY_H

#endif //LR11_GRAPHARRAY_H

#include "Graph.h";

class GraphArray
{
private:
    Graph **Array; //указатель на массив указателей
    unsigned int size;
    enum {SIN, TG, EXP};
public:
    //конструкторы
    GraphArray() {size = 0; Array = 0;} //default constructor
    GraphArray(unsigned int size)
    {
        Array = 0;
        this->size = size;
        setArraySize(this->size);
    }

    //methods
    void setArraySize(unsigned int size)
    {
        Clear();
        this->size = size;
        Array = new Graph*[size];
        for (unsigned int i = 0; i < size; i++)
            Array[i] = 0; //will change this later
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
            Array = 0;
        }
    }
    void setGraphType(unsigned int i, unsigned int type)
    {
        if (i >= 3)
            throw 11; //will fix this later неверный тип
        if (i < this->size)
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
};
