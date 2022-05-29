#include "figure.h"
#include <tuple>

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Pawn : public Figure
{
public:
    Pawn(char color)
    {
        if (color == 'b')
        {
            moves = {std::make_tuple(0, 1)};
            token = 'P';
            // token = '♙';
        }
        else
        {
            moves = {std::make_tuple(0, -1)};
            token = 'P';
            // token = '♟';
        }
        figure = 'P';
        num_of_moves = 2;
        this->color = color;
        taken = false;
        price = 1;
    }
};