#include "figure.h"
#include <tuple>
#ifndef FIGURE_H
#define FIGURE_H
using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class Queen : public Figure
{
public:
    Queen(char color)
    {
        moves = {
            std::make_tuple(1, 0), // east
            std::make_tuple(1, 1), // north-east
            std::make_tuple(-1, 0), // west
            std::make_tuple(-1, 1), //north-west
            std::make_tuple(0, 1), // north
            std::make_tuple(0, -1), // south
            std::make_tuple(-1, -1), // south-west
            std::make_tuple(1, -1) // south-east
        };
        moved = false;
        figure = 'Q';
        if (color == 'b')
            token = '♕';
        else
            token = '♛';
        num_of_moves = 8;
        this->color = color;
        taken = false;
        price = 9;   
    }
};
#endif