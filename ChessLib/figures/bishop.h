#include "figure.h"
#include <tuple>

using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class Bishop : public Figure
{
public:
    Bishop(char color)
    {
        moves = {
            std::make_tuple(1, 1), // north-east
            std::make_tuple(-1, 1), //north-west
            std::make_tuple(-1, -1), // south-west
            std::make_tuple(1, -1) // south-east
        };
        moved = false;
        figure = 'B';
        if (color == 'b')
            token = '♗';
        else
            token = '♝';
        num_of_moves = 8;
        this->color = color;
        taken = false;
        price = 3;   
    }
};
#endif