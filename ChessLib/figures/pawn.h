#include "figure.h"
#include <tuple>
#ifndef FIGURE_H
#define FIGURE_H
using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class Pawn : public Figure
{
public:
    Pawn(char color)
    {
        moves = {
            std::make_tuple(0, 1)
        };
        moved = false;
        if (color == 'b')
            token = '♙';
        else
            token = '♟';
        figure = 'P';
        num_of_moves = 2;
        this->color = color;
        taken = false;
        price = 1;   
    }
};
#endif