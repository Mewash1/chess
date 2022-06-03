#include "include_all_figures.h"
#ifndef PLAYER_H
#define PLAYER_H
using std::vector;

class Player
{
protected:
    bool human;
    char color;
    std::string name;
    vector<Figure *> figures;
    tuple<int, int> king_position;

public:
    Player() {};
    Player(char color, std::string name, bool human = true) noexcept;
    ~Player();

    char get_color() const noexcept { return color; }
    std::string get_name() const noexcept { return name; }
    vector<Figure *> get_figures() const noexcept { return figures; }
    bool get_humanity() const noexcept { return human; }
    tuple<int, int> get_king() const noexcept { return king_position; }
    void set_king(tuple<int, int> new_pos) noexcept; // set king position
    void add_figure(Figure* new_figure) {figures.push_back(new_figure);} // used when pawn is promoted
};
#endif
