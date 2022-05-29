#include "figure.h"
#include <tuple>

// #ifdef ROOK_H
// #define ROOK_H

using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class Rook : public Figure
{
public:
    Rook(char color)
    {
        moves = {
            std::make_tuple(1, 0), // east
            std::make_tuple(-1, 0), // west
            std::make_tuple(0, 1), // north
            std::make_tuple(0, -1) // south
        };
        figure = 'R';
        if (color == 'b')
            // token = '♖';
            token = 'R';
        else
            // token = '♖';
            token = 'R';
        num_of_moves = 8;
        this->color = color;
        taken = false;
        price = 5;   
    }
};
// #endif
