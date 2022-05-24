#include "figure.h"

#include <vector>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

// class pawn{
//     private:
//         bool moved;
//         char figure;
//         char color;
//         bool taken;

// geters
Figure::Figure(char figure)
{
    vector<char> figures = {
        'P', // PAWN
        'R', // ROOK
        'H', // HORSE
        'B', // BISHUP
        'Q', // QUEEN
        'K', // KING
    };
}

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
vector<tuple<int>> Figure::get_moves() const noexcept
// return moves from 00
{
    return {};
}

// seters
unsigned int Figure::take() noexcept
{
    taken = true;
    return price;
}
void Figure::set_figure(char new_name)
{
    // MAY COUSE ERROR, "if new_name in figures:"
    if ((std::find(figures.begin(), figures.end()), new_name) != figures.end()) // WARN!!! SKECHY STUFF
        figure = new_name;
    else
        throw std::invalid_argument("unknown figure name");
}

vector<tuple<int>> pawn_move(bool is_moved)
{
    vector<tuple<int>> temp = {(1, 0)};
    if (!is_moved)
        temp.push_back((2, 0));
    return temp;
}
vector<tuple<int>> hosre_move()
{
    vector<tuple<int>> temp = {
        (2, 1),
        (2, -1),
        (1, 2),
        (-1, 2),
        (-2, -1),
        (-2, 1),
        (-1, -2),
        (1, -2),
    };
    return temp;
}
vector<tuple<int>> bishup_move()
{
    vector<tuple<int>> temp = {};
    for (int i = 1; i <= 8; ++i)
    {
        temp.push_back((i, i));   // top right
        temp.push_back((i, -i));  // top left
        temp.push_back((-i, -i)); // bottom left
        temp.push_back((-i, i));  // bottom right
    }
    return temp;
}
vector<tuple<int>> rook_move()
{
    vector<tuple<int>> temp = {};
    for (int i = 1; i <= 8; ++i)
    {
        temp.push_back((0, i));  // right
        temp.push_back((0, -i)); // left
        temp.push_back((i, 0));  // top
        temp.push_back((-i, 0)); // down
    }
    return temp;
    return temp;
}
vector<tuple<int>> queen_move()
{
    vector<tuple<int>> temp = {(1, 0), (-1, 0), (0, 1), (0, -1)};
    return temp;
}