#include "figure.h"
#include <tuple>

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
        moved = false;
        figure = 'R';
        if (color == 'b')
            token = '♖';
        else
            token = '♜';
        num_of_moves = 8;
        this->color = color;
        taken = false;
        price = 5;   
    }
};
