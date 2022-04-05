//
// Created by User on 05.04.2022.
//
#include "math.h"

#ifndef LR8_POINT_H
#define LR8_POINT_H

#endif //LR8_POINT_H

//структура "точка"
struct Point
{
    int x;
    int y;
};

//найти рассояние от точки до начала координат
float findDistanceBetweenPointAndTheOriginOfCoordinates(Point p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

//найти расстояние между двумя точками
float findDistanceBetweenPointAndAnotherPoint(Point first_point, Point second_point)
{
    int a = second_point.y - first_point.y;
    int b = second_point.x - first_point.x;

    return sqrt(a * a + b * b);
}