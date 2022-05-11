#include "figure.h"

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

// class pawn{
//     private:
//         bool moved;
//         char name;
//         char color;
//         bool taken;

// geters
char figure::get_figure() const noexcept;
char figure::get_color() const noexcept;
bool figure::is_taken() const noexcept;
vector<tuple<int, int>> figure::get_moves() const noexcept; // return vector of all movements to further
// seters
unsigned int figure::take() noexcept
{
    taken = true;
    return price;
}
void figure::set_figure(char new_name)
{
    char figures[] = {
        'P', // PAWN
        'R', // ROOK
        'H', // HORSE
        'B', // BISHUP
        'Q', // QUEEN
        'K', // KING
    };
    figure = new_name;
}