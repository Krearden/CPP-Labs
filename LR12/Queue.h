//
// Created by User on 21.06.2022.
//

#ifndef LR12_QUEUE_H
#define LR12_QUEUE_H

#endif //LR12_QUEUE_H


#define DEFAULT_max_size 10

template <class T>
class Queue //класс "Очередь"
{
private:
    T *queueArray;
    unsigned int max_size;
    unsigned int element_counter;
    unsigned int begin;
    int end;
    enum {ISFULL, COUNTERTOOBIG, ISEMPTY};
public:
    //Конструктор
    Queue(int max_size_to_set = DEFAULT_max_size)
    {
        queueArray = new T[max_size_to_set];
        max_size = max_size_to_set;
        begin = 0;
        end = -1;
        element_counter = 0;
    }
    //getters and setters
    int get_max_size()
    {
        return max_size;
    }
    //public methods
    //добавить элемент в очередь
    void push(const T &new_element)
    {
        if (not IsFull())
        {
            end = (end + 1) % max_size;
            queueArray[end] = new_element;
            element_counter++;
        }
        else
        {
            throw ISFULL; //очередь переполнена
        }
    }
    //удалить элемент из очереди
    T pop()
    {
        if (not IsEmpty())
        {
            begin = (begin + 1) % max_size;
            element_counter--;
            return queueArray[begin - 1]; //возвращаем "удаляемый" элемент очереди
        }
        else
        {
            throw COUNTERTOOBIG; //индекс за пределами допустимого значения
        }
    }
    //обратиться к первому элементу очереди
    T first()
    {
        if (not IsEmpty())
        {
            return queueArray[begin];
        }
        else
        {
            throw ISEMPTY;
        }
    }
    //проверка на пустоту внутри
    bool IsEmpty()
    {
        return (element_counter == 0);
    }
    //проверка на полноту внутри
    bool IsFull()
    {
        return (element_counter == max_size);
    }
    //получить количество элементов очереди
    int getAmountOfElements()
    {
        return element_counter;
    }
    //напечатать очередь
    void printqueue()
    {
        if (not IsEmpty())
        {
            std::cout << "\nQueue: ";
            for (unsigned int i = begin; i <= end; i++)
            {
                std::cout << " " << queueArray[i];
            }
        }
        else
        {
            throw ISEMPTY;
        }
    }
    //перезагруженный оператор равенства
    const Queue<T>& operator=(const Queue<T>& queue_to_copy_from)
    {
        if (this == &queue_to_copy_from) return *this;
        if (this->max_size != queue_to_copy_from.max_size)
        {
            this->max_size = queue_to_copy_from.max_size;
        }
        delete[] this->queueArray;
        this->queueArray = new T[this->max_size];
        this->begin = queue_to_copy_from.begin;
        this->end = queue_to_copy_from.end;
        this->element_counter = queue_to_copy_from.element_counter;
        for (unsigned int i = 0; i < this->max_size; i++)
        {
            this->queueArray[i] = queue_to_copy_from.queueArray[i];
        }
    }
};