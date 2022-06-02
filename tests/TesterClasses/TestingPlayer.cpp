#include "TestingPlayer.h"
#include "../include_all_figures.h"

TestingPlayer::TestingPlayer(char color, std::string name, bool human) noexcept
{
    this->name = name;
    this->color = color;
    this->human = human;
    this->king_position = std::make_tuple(8,8);
}