#include "include_all_figures.h"
#ifndef PLAYER_H
#define PLAYER_H
using std::vector;

class Player
{
private:
    bool human;
    char color;
    std::string name;
    vector<Figure *> figures;

public:
    Player(char color, std::string name, bool human = true);
    char get_color() {return color;}
    std::string get_name() {return name;}
    vector<Figure *> get_figures() { return figures; }
    bool get_humanity() {return human;}
};
#endif
