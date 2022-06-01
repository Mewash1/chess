#include "player.h"
// #include "include_all_figures.h"

Player::Player(char color, std::string name, bool human) noexcept
{
    this->human = human;
    this->name = name;
    this->color = color;

    Rook *r1 = new Rook(color);
    Rook *r2 = new Rook(color);
    Bishop *b1 = new Bishop(color);
    Bishop *b2 = new Bishop(color);
    Knight *k1 = new Knight(color);
    Knight *k2 = new Knight(color);
    Queen *q = new Queen(color);
    King *k = new King(color);

    Pawn *p1 = new Pawn(color);
    Pawn *p2 = new Pawn(color);
    Pawn *p3 = new Pawn(color);
    Pawn *p4 = new Pawn(color);
    Pawn *p5 = new Pawn(color);
    Pawn *p6 = new Pawn(color);
    Pawn *p7 = new Pawn(color);
    Pawn *p8 = new Pawn(color);

    figures.push_back(r1);
    figures.push_back(k1);
    figures.push_back(b1);
    if (color == 'w')
    {
        figures.push_back(q);
        figures.push_back(k);
    }
    else
    {
        figures.push_back(k);
        figures.push_back(q);
    }

    figures.push_back(b2);
    figures.push_back(k2);
    figures.push_back(r2);

    figures.push_back(p1);
    figures.push_back(p2);
    figures.push_back(p3);
    figures.push_back(p4);
    figures.push_back(p5);
    figures.push_back(p6);
    figures.push_back(p7);
    figures.push_back(p8);
}

void Player::set_king(tuple<int, int> new_pos) noexcept
{
    this->king_position = new_pos;
}