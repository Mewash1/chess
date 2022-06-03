#include "player.h"
#include <tuple>
// #include "include_all_figures.h"

Player::Player(char color, std::string name, bool human) noexcept // creates all the figures for the player in the right order (depending on the color)
// also sets king's position depending on the color
{
    this->human = human;
    this->name = name;
    this->color = color;

    figures.push_back(new Rook(color));
    figures.push_back(new Horse(color));
    figures.push_back(new Bishop(color));
    if (color == 'w')
    {
        figures.push_back(new Queen(color));
        figures.push_back(new King(color));
    }
    else
    {
        figures.push_back(new King(color));
        figures.push_back(new Queen(color));
    }

    figures.push_back(new Bishop(color));
    figures.push_back(new Horse(color));
    figures.push_back(new Rook(color));

    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    figures.push_back(new Pawn(color));
    if (color == 'b')
    {
        king_position = std::make_tuple(0, 4);
    }
    else
    {
        king_position = std::make_tuple(7, 4);
    }
}

void Player::set_king(tuple<int, int> new_pos) noexcept // set new king position, used for checks
{
    this->king_position = new_pos;
}

Player::~Player()
{
    for (auto figure : figures)
        delete figure;
}