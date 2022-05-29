#include "include_all_figures.h"
// #ifdef PLAYER_H
// #define PLAYER_H
using std::vector;

class Player
{
private:
    bool human;
    char color;
    vector<Figure *> figures;

public:
    Player(char color, bool human = true);
    vector<Figure *> get_figures() { return figures; }
};
// #endif
