#include "figure.h"

#include <vector>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::find;
using std::tuple;
using std::vector;
// geters

char Figure::get_figure() // it's the first capital letter from the name of the figure
{
    return figure;
}
char Figure::get_color() const noexcept
{
    return color;
}
bool Figure::is_taken() const noexcept
{
    return taken;
}
vector<tuple<int, int>> Figure::get_moves() const noexcept
// return the shortest moves from 00
{
    return this->moves;
}

char Figure::get_token() const noexcept
{
    return this->figure;
}

int Figure::get_num_of_moves() const noexcept // returns how many shortest steps it takes for figure to perform its longest step
// eg. Queen's longest move at one try is 8, which is 8 * shortest step Queen can make, which is 1
{
    return num_of_moves;
}

// seters
unsigned int Figure::take() noexcept
{
    taken = true;
    return price;
}

void Figure::set_num_of_moves(int new_num) // used when pawn is promoted to a new figure
{
    num_of_moves = new_num;
}

bool Figure::is_moved() const noexcept // used when determining if casting is still possible
{
    return this->moved;
}