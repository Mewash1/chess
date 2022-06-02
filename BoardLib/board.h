#include "../PlayerLib/player.h"
#include <string>
#include <iostream>
#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    Player *player1, *player2, *current_player;
    Figure *table[8][8] = {{NULL}};
    vector<Figure *> graveyard;
    Figure *purgatory = NULL;
    bool validate_move(Figure *moved, tuple<int, int> old_cord, tuple<int, int> cords);
    bool at_check(Player *player);
    void take_figure(Figure *looser);

public:
    Board(Player *player1, Player *player2);
    void remove_figure();
    std::string move_figure(tuple<int, int>, tuple<int, int>, bool simulate = false);
    vector<tuple<int, int>> get_pawn_moves(tuple<int, int>);

    // void kill_figure(tuple<int, int>);
    void promote_figure(tuple<int, int>);
    void dump();
    Player *end_turn(); // end turn returns next player
    void print();
    void print_row(int i);
    void print_graveyard();
    void switch_current_player();
    bool mate_check();
};

#endif
