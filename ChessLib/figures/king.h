#include "figure.h"
#ifndef FIGURE_H
#define FIGURE_H
#include <tuple>
using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class King : public Figure
{
public:
    King(char color)
    {
        moves = {
            std::make_tuple(1, 0), // east
            std::make_tuple(-1, 0), // west
            std::make_tuple(0, 1), // north
            std::make_tuple(0, -1) // south
        };
        moved = false;
        figure = 'K';
        if (color == 'b')
            token = '♔';
        else
            token = '♚';
        this->color = color;
        taken = false;
        price = 10;   
    }
};

#endif