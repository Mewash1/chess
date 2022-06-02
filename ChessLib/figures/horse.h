#include "figure.h"
#include <tuple>
#ifndef HORSE_H
#define HORSE_H

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Horse : public Figure
{
public:
    Horse(char color)
    {
        moves = {
            std::make_tuple(1, 2),
            std::make_tuple(-1, 2),
            std::make_tuple(2, 1),
            std::make_tuple(-2, 1),

            std::make_tuple(1, -2),
            std::make_tuple(-1, -2),
            std::make_tuple(2, -1),
            std::make_tuple(-2, -1),
        };
        figure = 'H';
        if (color == 'b')
            token = 'h';
        // token = '♘';
        else
            token = 'H';
        // token = '♞';
        num_of_moves = 1;
        this->color = color;
        taken = false;
        price = 3;
    }
    char get_figure() {return figure;}
};
#endif
