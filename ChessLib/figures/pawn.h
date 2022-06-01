#include "figure.h"
#include <tuple>
#ifndef PAWN_H
#define PAWN_H

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Pawn : public Figure
{
public:
    Pawn(char color)
    {
        token = 'P';
        figure = 'P';
        num_of_moves = 1;
        this->color = color;
        taken = false;
        price = 1;
    }
};
#endif
