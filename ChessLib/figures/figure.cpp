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

char Figure::get_figure() const noexcept
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
// return moves from 00
{
    return this->moves;
}

char Figure::get_token() const noexcept
{
    // return this->token;
    return this->figure;
}

int Figure::get_num_of_moves() const noexcept
{
    return num_of_moves;
}
// seters
unsigned int Figure::take() noexcept
{
    taken = true;
    return price;
}

void Figure::set_num_of_moves(int new_num)
{
    num_of_moves = new_num;
}

bool Figure::is_moved() const noexcept
{
    return this->moved;
}