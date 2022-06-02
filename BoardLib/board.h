#include "../PlayerLib/player.h"
#include <string>
#include <iostream>
#ifndef BOARD_H
#define BOARD_H

class Board
{
protected:
    Player *player1, *player2, *current_player;
    Figure *table[8][8] = {{NULL}};
    vector<Figure *> graveyard;
    Figure *purgatory = NULL;
    bool validate_move(Figure *moved, tuple<int, int> old_cord, tuple<int, int> cords);
    void take_figure(Figure *looser);
    std::string long_cast() noexcept;
    std::string short_cast() noexcept;
    std::string castling(tuple<int, int>) noexcept;

public:
    Board(){}; // used only for testing
    Board(Player *player1, Player *player2);
    void remove_figure();
    std::string move_figure(tuple<int, int>, tuple<int, int>, bool simulate = false);
    vector<tuple<int, int>> get_pawn_moves(tuple<int, int>);
    bool at_check(Player *player);

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
