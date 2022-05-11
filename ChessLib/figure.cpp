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
char figure::get_figure() const noexcept
{
    return figure;
}
char figure::get_color() const noexcept
{
    return color;
}
bool figure::is_taken() const noexcept
{
    return is_taken;
}
vector<tuple<int>> figure::get_moves() const noexcept
// return moves from 00
{
    switch (figure)
    {
    case 'K':
        return king_move();
        break;

    default:
        throw std::overflow_error("Asking for move that is not defined");
        break;
    }
    return {};
}

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
    if (std::find(std::begin(figures), std::end(figures), new_name))
        figure = new_name;
    else
        throw std::invalid_argument("unknown figure name");
}

vector<tuple<int>> king_move()
{
    vector<tuple<int>> temp = {(1, 0), (-1, 0), (0, 1), (0, -1)};
    return temp;
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