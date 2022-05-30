#include "figure.h"
#include <tuple>
#ifndef KING_H
#define KING_H
using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class King : public Figure
{
public:
    King(char color)
    {
        moves = {
            std::make_tuple(1, 0),   // east
            std::make_tuple(1, 1),   // north-east
            std::make_tuple(-1, 0),  // west
            std::make_tuple(-1, 1),  // north-west
            std::make_tuple(0, 1),   // north
            std::make_tuple(0, -1),  // south
            std::make_tuple(-1, -1), // south-west
            std::make_tuple(1, -1)   // south-east
        };
        figure = 'K';
        if (color == 'b')
            token = 'k';
        // token = '♔';
        else
            token = 'K';
        // token = '♚';
        num_of_moves = 1;
        this->color = color;
        taken = false;
        price = 10;
    }
};
#endif
