#include "../include_all_figures.h"
#include "../../PlayerLib/player.h"
#ifndef TESTPLAYER_H
#define TESTPLAYER_H
using std::vector;

class TestingPlayer : public Player
{
public:
    TestingPlayer(char color, std::string name, bool human) noexcept;
};

#endif