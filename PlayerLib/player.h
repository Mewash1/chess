#include "include_all_figures.h"
#ifndef PLAYER_H
#define PLAYER_H
using std::vector;

class Player
{
private:
    bool human;
    char color;
    vector<Figure *> figures;

public:
    Player(char color, bool human = true);
    char get_color() {return color;}
    vector<Figure *> get_figures() { return figures; }
};
#endif
