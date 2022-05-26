//
// Created by User on 19.05.2022.
//

#ifndef LR9_LOGICALELEMENTAND_H
#define LR9_LOGICALELEMENTAND_H

#endif //LR9_LOGICALELEMENTAND_H

#define AMOUNT_OF_OK_INPUTS 4

////get length of unsigned short array DONT WORK CORRECTLY
//unsigned short getLengthOfUnsignedShortArray(unsigned short *array)
//{
//    if (array)
//        return sizeof(array) / sizeof(array[0]);
//    return 0;
//}


//проверка подходящее ли число для количества входов логического "И"
bool checkIfNumberOfInputsIsOK(unsigned short number)
{
    unsigned short okay_array[] = {2, 3, 4, 8};
    for (short i = 0; i < AMOUNT_OF_OK_INPUTS; i++)
    {
        if (number == okay_array[i])
        {
            return true;
        }
    }
    return false;
}


//класс - Логический элемент "И"
class LogicalElementAND
{
private:
    unsigned short number_of_inputs;
    unsigned short *inputs;
    unsigned short exit_signal = 1;

public:
    LogicalElementAND()
    {
        number_of_inputs = 2;
        unsigned short data_array[] = {0, 0};
        setInputsWithDataArray(data_array);
    }
    LogicalElementAND(unsigned short number_of_inputs, unsigned short *data_array)
    {
        this->number_of_inputs = number_of_inputs;
        inputs = new unsigned short[number_of_inputs];
        setInputsWithDataArray(data_array);
    }
    LogicalElementAND(unsigned short number_of_inputs, const char *string)
    {
        this->number_of_inputs = number_of_inputs;
        inputs = new unsigned short[number_of_inputs];
        setInputsWithString(string);
    }
    //get number of inputs
    unsigned short getNumberOfInputs()
    {
        return this->number_of_inputs;
    }
    //set number of inputs
    void setNumberOfInpts(unsigned short number)
    {
        bool check = checkIfNumberOfInputsIsOK(number);
        if (check)
            this->number_of_inputs = number;
//        printf("\nНе забудьте поменять сами входные сигналы!");
    }
    //set inputs of logical "AND" with string
    void setInputsWithString(const char *string)
    {
        if (inputs)
        {
            unsigned short data_array[this->number_of_inputs];
            for (short i = 0; i < this->number_of_inputs; i++)
            {
                data_array[i] = (string[i] == '1') ? 1 : 0;
            }
            setInputsWithDataArray(data_array);
        }
    }
    //set inputs of logical "AND" with data array
    void setInputsWithDataArray(unsigned short *data_array)
    {
        this->inputs = new unsigned short[this->number_of_inputs];
        if (number_of_inputs)
        {
            if (this->inputs)
            {
                for (short i = 0; i < number_of_inputs; i++)
                {
                    inputs[i] = (data_array[i] == 0) ? 0 : 1;
                }
            }
        }
    }
//    //get inputs array to dispaly on display :) NEED FIX!
//    char* getInputsAsString()
//    {
//        char inputs_as_string[this->number_of_inputs];
//        for (short i = 0; i < this->number_of_inputs; i++)
//        {
//            inputs_as_string[i] = (char)inputs[i];
//        }
//        return inputs_as_string;
//    }
    char * getInputsAsString()
    {
        char* string_for_printf_inputs = new char[this->number_of_inputs];
        string_for_printf_inputs[this->number_of_inputs] = '\0';
        for (short i = 0; i < this->number_of_inputs; i++)
        {
            string_for_printf_inputs[i] = (inputs[i] == 0) ? '0' : '1';
        }
        return string_for_printf_inputs;
    }
    //find exit signal based of input signals NEED FIX
    unsigned short findExitSignal()
    {
        if (inputs)
        {

            for (short i = 0; i < number_of_inputs; i++)
            {
                this->exit_signal *= this->inputs[i];
            }
        }

        return this->exit_signal;
    }

    //Ниже перезагружены операторы сравнения
    bool operator==(LogicalElementAND &logical_two)
    {
        unsigned short a = this->findExitSignal();
        unsigned short b = logical_two.findExitSignal();

        return a == b;
    }
    bool operator>(LogicalElementAND &logical_two)
    {
        unsigned short a = this->findExitSignal();
        unsigned short b = logical_two.findExitSignal();

        return a > b;
    }
    bool operator<(LogicalElementAND &logical_two)
    {
        unsigned short a = this->findExitSignal();
        unsigned short b = logical_two.findExitSignal();

        return a < b;
    }

};
