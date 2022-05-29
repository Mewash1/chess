#include "figure.h"
#include <tuple>

// #ifdef BISHOP_H
// #define BISHOP_H

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Bishop : public Figure
{
public:
    Bishop(char color)
    {
        moves = {
            std::make_tuple(1, 1),   // north-east
            std::make_tuple(-1, 1),  // north-west
            std::make_tuple(-1, -1), // south-west
            std::make_tuple(1, -1)   // south-east
        };
        moved = false;
        figure = 'B';
        if (color == 'b')
            token = 'B';
        // token = '♗';
        else
            token = 'B';
        // token = '♝';
        num_of_moves = 8;
        this->color = color;
        taken = false;
        price = 3;
    }
};
// #endif