#include "figure.h"
#include <tuple>
using std::cout;
using std::endl;
using std::vector;
using std::tuple;


class King : public Figure
{
public:
    King(char color)
    {
        moves = {
            std::make_tuple(1, 0),
            std::make_tuple(-1, 0),
            std::make_tuple(0, 1), 
            std::make_tuple(0, -1)
        };
        moved = false;
        figure = 'K';
        this->color = color;
        taken = false;
        price = 10;   
    }
};