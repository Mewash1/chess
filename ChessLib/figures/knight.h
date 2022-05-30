#include "figure.h"
#include <tuple>
#ifndef KNIGHT_H
#define KNIGHT_H

using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class Knight : public Figure
{
public:
    Knight(char color)
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
        figure = 'k';
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
};
#endif
